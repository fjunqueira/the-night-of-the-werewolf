#include <Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <math.h>
#include <time.h>
#include "Image.h"
#include "ImageLoader.h"
#include "Layer.h"
#include "AssetManager.h"
#include "Cop.h"
#include "Vector2.h"
#include <functional>
#include "Player.h"

AssetManager manager;

Image* background;

Image* gameoverBackground;
Image* gameoverText;

Player* player;

std::vector<GameObject*> gameObjects;

int points;

void postRedisplay()
{
	glutPostRedisplay();
}

void disableUnneededPixelOperations()
{
	/*
	* Disable stuff that's likely to slow down
	* glDrawPixels.(Omit as much of this as possible,
	* when you know in advance that the OpenGL state is
	* already set correctly.)
	*/
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
	glDisable(GL_LOGIC_OP);
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_TEXTURE_1D);
	glDisable(GL_TEXTURE_2D);
	glPixelTransferi(GL_MAP_COLOR, GL_FALSE);
	glPixelTransferi(GL_RED_SCALE, 1);
	glPixelTransferi(GL_RED_BIAS, 0);
	glPixelTransferi(GL_GREEN_SCALE, 1);
	glPixelTransferi(GL_GREEN_BIAS, 0);
	glPixelTransferi(GL_BLUE_SCALE, 1);
	glPixelTransferi(GL_BLUE_BIAS, 0);
	glPixelTransferi(GL_ALPHA_SCALE, 1);
	glPixelTransferi(GL_ALPHA_BIAS, 0);


	/*
	* Disable extensions that could slow down
	* glDrawPixels.(Actually, you should check for the
	* presence of the proper extension before making
	* these calls.I omitted that code for simplicity.)
	*/
#if GL_SGI_index_func 
	(glDisable(GL_INDEX_TEST_SGI);
#endif

}

void displayText(float x, float y, int r, int g, int b, std::string string) {
	int j = string.length();

	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void gameover(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	disableUnneededPixelOperations();

	glRasterPos2f(-1, -1);
	glDrawPixels(gameoverBackground->getWidth(), gameoverBackground->getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		gameoverBackground->getPixels());

	auto pointsText = "SCORE: " + std::to_string(points);
	displayText(-0.15, 0.7, 1, 0, 0, pointsText);

	glutSwapBuffers();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	disableUnneededPixelOperations();

	Image viewport = Image(background->getWidth(), background->getHeight(), background->getPixels());

	std::sort(gameObjects.begin(), gameObjects.end(), [&](GameObject* first, GameObject* second)
	{
		return first->getZ() < second->getZ();
	});

	std::for_each(gameObjects.begin(), gameObjects.end(), [&](GameObject* gameObject)
	{
		gameObject->update(10);
		gameObject->plotTo(&viewport);
	});

	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* gameObject)
	{
		return gameObject->getPosition().x < -100;

	}), gameObjects.end());

	if (player->isDead())
	{
		gameoverBackground = new Image(viewport.getWidth(), viewport.getHeight(), viewport.getPixels());
		gameoverText->plotTo(gameoverBackground);
		glutDisplayFunc(gameover);
		return;
	}

	glRasterPos2f(-1, -1);
	glDrawPixels(viewport.getWidth(), viewport.getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		viewport.getPixels());

	glutSwapBuffers();
}

void restart()
{
	gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* gameObject)
	{
		return dynamic_cast<Cop*>(gameObject) != NULL;

	}), gameObjects.end());

	points = 0;
	player->revive();
	delete gameoverBackground;
	glutDisplayFunc(display);
}

void keyboard(unsigned char key, int x, int y)
{
	player->handleInput(key);

	if (key == '\r' && player->isDead())
		restart();
}

void CALLBACK addEnemy(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	if (!player->isDead())
	{
		points++;

		Image** idleCopSprites = new Image*[10]
		{
			manager.getAsset("idle_cop_1"),
			manager.getAsset("idle_cop_2"),
			manager.getAsset("idle_cop_3"),
			manager.getAsset("idle_cop_4"),
			manager.getAsset("idle_cop_5"),
			manager.getAsset("idle_cop_6"),
			manager.getAsset("idle_cop_7"),
			manager.getAsset("idle_cop_8"),
			manager.getAsset("idle_cop_9"),
			manager.getAsset("idle_cop_10"),
		};

		if (rand() % 2 > 0)
			gameObjects.push_back(new Cop(Animation(10, idleCopSprites), Vector2(background->getWidth(), 85), 3, player));
		else
			gameObjects.push_back(new Cop(Animation(10, idleCopSprites), Vector2(background->getWidth(), 85), 5, player));
	}
}

void initGameData()
{
	srand(time(NULL));

	manager = AssetManager();
	manager.loadAssets();

	background = manager.getAsset("background");
	gameoverText = manager.getAsset("gameover");

	gameObjects.push_back(new Layer(manager.getAsset("largeBushes"), Vector2(0, 105), 1));
	gameObjects.push_back(new Layer(manager.getAsset("smallBushes"), Vector2(0, 85), 2));
	gameObjects.push_back(new Layer(manager.getAsset("floor"), 4));

	Image** runningSprites = new Image*[8]
	{
		manager.getAsset("running_wolf_1"),
		manager.getAsset("running_wolf_2"),
		manager.getAsset("running_wolf_3"),
		manager.getAsset("running_wolf_4"),
		manager.getAsset("running_wolf_5"),
		manager.getAsset("running_wolf_6"),
		manager.getAsset("running_wolf_7"),
		manager.getAsset("running_wolf_8")
	};

	Image** jumpingSprites = new Image*[7]
	{
		manager.getAsset("jumping_wolf_1"),
		manager.getAsset("jumping_wolf_3"),
		manager.getAsset("jumping_wolf_5"),
		manager.getAsset("jumping_wolf_6"),
		manager.getAsset("jumping_wolf_5"),
		manager.getAsset("jumping_wolf_3"),
		manager.getAsset("jumping_wolf_1"),
	};

	player = new Player(Animation(8, runningSprites), Animation(7, jumpingSprites), Vector2(background->getWidth() / 2 - 100, 85), 5);

	gameObjects.push_back(player);

	UINT_PTR timerid = SetTimer(NULL, 0, 1000, &addEnemy);

	PlaySound(TEXT("..\\assets\\Haunted_House_Hurried.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void initWorld(void)
{
	//clear color
	glClearColor(0, 0, 0, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//initialize viewing values
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv)
{
	initGameData();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(801, 481);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("The Running Werewolf");

	glutKeyboardFunc(keyboard);
	initWorld();
	glutDisplayFunc(display);
	glutIdleFunc(postRedisplay);
	glutMainLoop();

	return 0;
}