#include "Rigidbody.h"

Rigidbody::Rigidbody() {
	init();
}

void Rigidbody::init(float _mass, int _width, int _height, float _frictionCo)
{
	mass = _mass;
	collider = new Collider(_width, _height, _frictionCo);
}

void Rigidbody::addForce(Roaduser _roaduser, float _force)
{
	// add force
}