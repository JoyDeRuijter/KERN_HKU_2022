#include "Rigidbody.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Rigidbody::Rigidbody() 
{
	mass = 1;
	frictionCo = 0.8f;	//Rubber on concrete
	gravity = 9.81f;
}


float Rigidbody::calculateAcceleration(float _currentVelocity, float _mass, float _force)
{
	float necessaryForce = calculateFriction(_mass);
	return (_force - necessaryForce * _currentVelocity)/_mass;

}

float Rigidbody::calculateFriction(float _mass)
{
	return _mass * gravity * frictionCo;
}

float Rigidbody::calculateVelocity(float _currentVelocity, float _mass, float _force, float _time)
{
	float acceleration = calculateAcceleration(_currentVelocity, _mass, _force);
	return _currentVelocity + acceleration * _time;
}

float Rigidbody::addForce(float _axis, float _force)
{
	_axis += _force;
	return _axis;
}