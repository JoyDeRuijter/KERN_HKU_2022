#include "Collider.h"

Collider::Collider(Vector2D _position, int _width, int _height, float _frictionCo)
{
	position = Vector2D(_position.x, _position.y);
	isTouchingSomething = false;
	width = _width;
	height = _height;
	frictionCo = _frictionCo;
}

bool Collider::isTouching(Collider& _collider)
{
	// this collider
	float thisMinX = position.x; //left border of collider
	float thisMaxX = position.x + width; //right border of collider
	float thisMinY = position.y; // top border of collider
	float thisMaxY = position.y + height; // bottom border of collider

	// parameter collider
	float thatMinX = _collider.position.x; //left border of collider
	float thatMaxX = _collider.position.x + width; //right border of collider
	float thatMinY = _collider.position.y; // top border of collider
	float thatMaxY = _collider.position.y + height; // bottom border of collider
	
	//if ((thisMinX <= thatMaxX && thisMinX >= thatMinX) && (thisMinY >= thatMinY && thisMinY <= thatMaxY)
	//	&& (thisMaxX >=)

	if(thisMaxY >= thatMinY && thisMinY <= thatMaxY && thisMaxX >= thatMinX && thisMinX <= thatMaxX)
		return true;
	else
		return false;
}