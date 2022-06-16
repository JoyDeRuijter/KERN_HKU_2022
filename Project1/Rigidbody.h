#pragma once
#include "Collider.h"
#include "Roaduser.h"

class Roaduser;

class Rigidbody
{
	public:
	Rigidbody();
		float mass;
		Collider* collider;
		void addForce(Roaduser _roaduser, float _force);
		void init(float _mass, int _width, int _height, float _frictionCo);
};

