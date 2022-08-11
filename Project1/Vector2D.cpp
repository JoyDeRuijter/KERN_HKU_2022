// Joy de Ruijter - 2022

#include "Vector2D.h"
#include <Cmath>

Vector2D::Vector2D()
{}

Vector2D::Vector2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2D Vector2D::add(Vector2D _otherVector2) // Add a Vector2D to the current Vector2D and return the result
{
	return Vector2D(this->x + _otherVector2.x, this->y + _otherVector2.y);
}

Vector2D Vector2D::subtract(Vector2D _otherVector2) // Subtract a Vector2D from the current Vector2D and return the result
{
	return Vector2D(this->x - _otherVector2.x, this->y + _otherVector2.y);
}

float Vector2D::magnitude() // Calculate the magnitude of the current Vector2D 
{
	return sqrt(x * x + y * y);
}

float Vector2D::distance(Vector2D _otherVector2) // Calculate the distance between this Vector2D and the provided Vector2D and return the result
{
	return this->subtract(_otherVector2).magnitude();	
}