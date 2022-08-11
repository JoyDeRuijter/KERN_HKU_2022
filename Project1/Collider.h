#pragma once
#include "Vector2D.h"
class Collider
{
	public:
		Collider(Vector2D _position, Vector2D _size);
		Collider(float _top, float _left, float _height, float _width);
		
		float top;
		float left;
		float height;
		float width;
		bool isTouchingSomething;
		
		bool isTouching(Collider _collider);
};

