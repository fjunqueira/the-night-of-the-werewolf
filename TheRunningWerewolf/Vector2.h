#pragma once
#include <math.h> 
struct Vector2
{
public:
	int x, y;

	Vector2();
	Vector2(int x, int y);
	Vector2 operator+(const Vector2 & other);
	Vector2 operator-(const Vector2 & other);
	Vector2 operator*(const int value);
	float getMagnitude();
	~Vector2();
};

