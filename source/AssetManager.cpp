#include "AssetManager.h"

AssetManager::AssetManager() {
}

void AssetManager::loadAssets() {
    auto loader = ImageLoader();

    this->assets.insert(std::pair<std::string, Image *>("background", this->loadImage(&loader,
                                                                                      "../assets/Scenery/Background/BG.ptm")));
    this->assets.insert(std::pair<std::string, Image *>("floor", this->loadImage(&loader,
                                                                                 "../assets/Scenery/MiddleGround/5_extended.ptm")));
    this->assets.insert(std::pair<std::string, Image *>("smallBushes", this->loadImage(&loader,
                                                                                       "../assets/Scenery/MiddleGround/4_extended.ptm")));
    this->assets.insert(std::pair<std::string, Image *>("largeBushes", this->loadImage(&loader,
                                                                                       "../assets/Scenery/MiddleGround/3_extended.ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("gameover", this->loadImage(&loader, "../assets/GameOver.ptm")));

    this->loadWolf(&loader);
    this->loadWolfJump(&loader);
    this->loadCop(&loader);
}

Image *AssetManager::getAsset(std::string name) {
    return this->assets.at(name);
}

AssetManager::~AssetManager() {
    std::for_each(this->assets.begin(), this->assets.end(), [&](std::pair<std::string, Image *> asset) {
        delete asset.second;
    });
}

Image *AssetManager::loadImage(ImageLoader *loader,const char *path) {
    auto ptm = loader->loadPTM(path);

    auto image = new Image(ptm.width, ptm.height, ptm.pixels);

    delete[] ptm.pixels;

    return image;
}

void AssetManager::loadWolf(ImageLoader *loader) {
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_1",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (1).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_2",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (2).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_3",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (3).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_4",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (4).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_5",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (5).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_6",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (6).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_7",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (7).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("running_wolf_8",
                                                        this->loadImage(loader, "../assets/Werewolf/Run (8).ptm")));
}

void AssetManager::loadWolfJump(ImageLoader *loader) {
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_1",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (1).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_2",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (2).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_3",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (3).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_4",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (4).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_5",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (5).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_6",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (6).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_7",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (7).ptm")));
    this->assets.insert(std::pair<std::string, Image *>("jumping_wolf_8",
                                                        this->loadImage(loader, "../assets/Werewolf/Jump (8).ptm")));
}

void AssetManager::loadCop(ImageLoader *loader) {
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_1", this->loadImage(loader, "../assets/Police/Idle (1).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_2", this->loadImage(loader, "../assets/Police/Idle (2).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_3", this->loadImage(loader, "../assets/Police/Idle (3).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_4", this->loadImage(loader, "../assets/Police/Idle (4).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_5", this->loadImage(loader, "../assets/Police/Idle (5).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_6", this->loadImage(loader, "../assets/Police/Idle (6).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_7", this->loadImage(loader, "../assets/Police/Idle (7).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_8", this->loadImage(loader, "../assets/Police/Idle (8).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_9", this->loadImage(loader, "../assets/Police/Idle (9).ptm")));
    this->assets.insert(
            std::pair<std::string, Image *>("idle_cop_10", this->loadImage(loader, "../assets/Police/Idle (10).ptm")));
}