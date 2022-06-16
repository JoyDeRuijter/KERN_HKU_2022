#include "Vector2D.h"
#include <Cmath>

Vector2D::Vector2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2D Vector2D::add(Vector2D _otherVector2)
{
	return Vector2D(this->x + _otherVector2.x, this->y + _otherVector2.y);
}

Vector2D Vector2D::subtract(Vector2D _otherVector2)
{
	return Vector2D(this->x - _otherVector2.x, this->y + _otherVector2.y);
}

float Vector2D::magnitude()
{
	return sqrt(x * x + y * y);
}

float Vector2D::distance(Vector2D _otherVector2)
{
	return this->subtract(_otherVector2).magnitude();	
}