#include "Vector2.h"



Vector2::Vector2()
{
}

Vector2::Vector2(int x, int y) :x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2 & other)
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2 & other)
{
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const int value)
{
	return Vector2(this->x * value, this->y * value);
}

float Vector2::getMagnitude()
{
	return sqrtf(powf(x, 2) + pow(y, 2));
}

Vector2::~Vector2()
{
}
