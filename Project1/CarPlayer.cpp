#include "CarPlayer.h"

//CarPlayer::CarPlayer() : Roaduser()
//{
//	startLane = 1;
//	currentLane = startLane;
//	position = Vector2D(getLanePosition(), 648);
//	texturePath = "Textures/Player1.png";
//	initializeTextureAndSprite();
//}
//
//float CarPlayer::getLanePosition()
//{
//	return lanePositions[currentLane];
//}
//
//void CarPlayer::moveLeft()
//{
//	if (currentLane >= 1)
//		currentLane--;
//
//	position.x = getLanePosition();
//}
//
//void CarPlayer::moveRight()
//{
//	if (currentLane <= 2)
//		currentLane++;
//
//	position.x = getLanePosition();
//}

CarPlayer::CarPlayer(float _startX, float _startY, float _force) : Roaduser()
{
	playerSpeed = 20;

	texturePath = "Textures/Player1.png";

	rigidbody = new Rigidbody();
	initializeTextureAndSprite();

	rigidbody->forceForward = 10;
	rigidbody->forceSideways = 0;
	rigidbody->xVelocity = 0;
	rigidbody->yVelocity = 1;

	position = Vector2D(_startX, _startY);
	size = Vector2D(69, 123);

	roaduserSprite.setPosition(Vector2f(position.x, position.y));
}

void CarPlayer::moveLeft()
{
	rigidbody->forceSideways = rigidbody->addForce(rigidbody->forceSideways, -playerSpeed);
}

void CarPlayer::moveRight()
{
	rigidbody->forceSideways = rigidbody->addForce(rigidbody->forceSideways, playerSpeed);
}

void CarPlayer::update(float _time)
{
	position.x += rigidbody->calculateVelocity(rigidbody->xVelocity, rigidbody->mass, rigidbody->forceSideways, _time);
	roaduserSprite.setPosition(Vector2f(position.x, position.y));
	if (position.x <= 190)
		position.x = 190;
	if (position.x >= 690)
		position.x = 690;
}