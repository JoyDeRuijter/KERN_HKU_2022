// Joy de Ruijter - 2022

#include "CarPlayer.h"

CarPlayer::CarPlayer(float _startX, float _startY, float _force) : Roaduser()
{
	playerSpeed = 20;

	texturePath = "Textures/Player1.png";
	initializeTextureAndSprite();

	rigidbody = new Rigidbody();
	rigidbody->forceForward = 10;
	rigidbody->forceSideways = 0;
	rigidbody->xVelocity = 0;
	rigidbody->yVelocity = 1;

	position = Vector2D(_startX, _startY);
	size = Vector2D(69, 123);
	roaduserSprite.setPosition(Vector2f(position.x, position.y));
}

void CarPlayer::moveLeft() // Move the player to the left
{
	rigidbody->forceSideways = rigidbody->addForce(rigidbody->forceSideways, -playerSpeed);
}

void CarPlayer::moveRight() // Move the player to the right
{
	rigidbody->forceSideways = rigidbody->addForce(rigidbody->forceSideways, playerSpeed);
}

void CarPlayer::update(float _time) // Update the position of the player
{
	position.x += rigidbody->calculateVelocity(rigidbody->xVelocity, rigidbody->mass, rigidbody->forceSideways, _time);
	roaduserSprite.setPosition(Vector2f(position.x, position.y));
	if (position.x <= 190)
		position.x = 190;
	if (position.x >= 690)
		position.x = 690;
}