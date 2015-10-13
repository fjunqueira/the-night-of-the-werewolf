#include "Vector2.h"


Vector2::Vector2() : x(0), y(0) {
}

Vector2::Vector2(int x, int y) : x(x), y(y) {
}

Vector2 Vector2::operator+(const Vector2 &other) {
    return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(const Vector2 &other) {
    return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator*(const int value) {
    return Vector2(this->x * value, this->y * value);
}

float Vector2::getMagnitude() {
    return sqrtf((float) (powf(x, 2) + pow(y, 2)));
}

Vector2::~Vector2() {
}
