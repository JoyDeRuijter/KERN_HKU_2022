#pragma once
#include "Collider.h"
#include "Roaduser.h"

class Roaduser;

class Rigidbody
{
	public:
		Rigidbody();

		float mass;
		float forceForward;
		float forceSideways;
		float xVelocity;
		float yVelocity;
		float frictionCo;
		float gravity;
		
		float calculateAcceleration(float _currentVelocity, float _mass, float _force);
		float calculateFriction(float _mass);
		float calculateVelocity(float _currentVelocity, float _mass, float _force, float _time);
		float addForce(float _axis, float _force);
};

