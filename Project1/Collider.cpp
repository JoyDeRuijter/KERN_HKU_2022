// Joy de Ruijter - 2022

#include "Collider.h"

Collider::Collider(Vector2D _position, Vector2D _size)
{
	top = _position.y;
	left = _position.x;
	height = _size.y;
	width = _size.x;
}

Collider::Collider(float _top, float _left, float _height, float _width)
{
	top = _top;
	left = _left;
	height = _height;
	width = _width;
}

bool Collider::isTouching(Collider _collider) // Checks if this collider is touching the provided collider
{
	// this collider
	float thisMinX = left; //left border of collider
	float thisMaxX = left + width; //right border of collider
	float thisMinY = top; // top border of collider
	float thisMaxY = top + height; // bottom border of collider

	// parameter collider
	float thatMinX = _collider.left; //left border of collider
	float thatMaxX = _collider.left + _collider.width; //right border of collider
	float thatMinY = _collider.top; // top border of collider
	float thatMaxY = _collider.top + height; // bottom border of collider
	
	if (thisMinX <= thatMaxX && thisMaxX >= thatMinX && thisMaxY >= thatMinY && thisMinY <= thatMaxY)
		return true;
	else
		return false;
}

