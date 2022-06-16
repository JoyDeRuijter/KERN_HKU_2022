#pragma once
#include "Vector2D.h"
class Collider
{
	public:
		float frictionCo;
		bool isTouchingSomething;
		Vector2D position; // vind een manier om aan de positie van de roaduser te komen waar de specifieke collider aan vast zit
		int width;
		int height;
		bool isTouching(Collider& _collider);
		Collider(Vector2D _position, int _width, int _height, float _frictionCo);
};

