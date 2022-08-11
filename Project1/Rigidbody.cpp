// Joy de Ruijter - 2022

#include "Rigidbody.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Rigidbody::Rigidbody() 
{
	mass = 1;
	frictionCo = 0.8f;	//Rubber on concrete
	gravity = 9.81f;
}

float Rigidbody::calculateAcceleration(float _currentVelocity, float _mass, float _force) // Calculate the acceleration of the rigidbody, based on the necessaryforce
{
	float necessaryForce = calculateFriction(_mass);
	return (_force - necessaryForce * _currentVelocity)/_mass;
}

float Rigidbody::calculateFriction(float _mass) // Calculate the friction, based on the mass & gravity and the friction coëfficient of rubber on concrete
{
	return _mass * gravity * frictionCo;
}

float Rigidbody::calculateVelocity(float _currentVelocity, float _mass, float _force, float _time) // Calculate the velocity, based on the acceleration
{
	float acceleration = calculateAcceleration(_currentVelocity, _mass, _force);
	return _currentVelocity + acceleration * _time;
}

float Rigidbody::addForce(float _axis, float _force) // Add a force to a certain axis of the rigidbody
{
	_axis += _force;
	return _axis;
}