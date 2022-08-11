#include "CarNPC.h"
#include <sstream>
#include <iostream>

//CarNPC::CarNPC() : Roaduser()
//{
//	position = Vector2D(getStartLane(), 90);
//	texturePath = "Textures/Player2.png";
//	initializeTextureAndSprite();
//}
//
//float CarNPC::getStartLane()
//{
//	startLane = rand() % 4;
//	currentLane = startLane;
//	return lanePositions[currentLane];
//}
//
//void CarNPC::update()
//{
//	Roaduser::update();
//	position.y += yVelocity;
//}

CarNPC::CarNPC(float _startX, float _startY, float _force) : Roaduser()
{
	rigidbody = new Rigidbody();
	rigidbody->forceForward = _force;
	rigidbody->forceSideways = 0;
	rigidbody->xVelocity = 0;
	rigidbody->yVelocity = 0;
	position.x = setStartPosition();
	position.y = -120;
	size = Vector2D(69, 123);
	texturePath = "Textures/Player2.png";
	initializeTextureAndSprite();


	roaduserSprite.setPosition(Vector2f(position.x, position.y));

	direction = setDirection();
}

void CarNPC::hitEnd()
{
	position.y = 1;
}

void CarNPC::update(float _time)
{
	position.y += rigidbody->calculateVelocity(rigidbody->yVelocity, rigidbody->mass, rigidbody->forceForward, _time);
	roaduserSprite.setPosition(Vector2f(position.x, position.y));

	// horizontal movement
	position.x += rigidbody->calculateVelocity(rigidbody->xVelocity, rigidbody->mass, 50, _time) * direction;
	if (position.x <= 190 || position.x >= 690)
		direction = -direction;
}

float CarNPC::setStartPosition()
{
	std::vector<int> startPositions = {240, 440, 640};
	int startPos = rand()%3;
	return startPositions[startPos];
}

float CarNPC::setDirection()
{
	std::vector<float>directions{1, -1};
	float startDirection = rand()%2;
	return directions[startDirection];
}

