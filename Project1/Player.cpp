#include "Player.h"

Player::Player(int startLane)
{
	lanePosition = startLane;

	position.x = getLanePosition();
	position.y = 648;
}

void Player::InitializeTextureAndSprite()
{
	if (playerTexture.loadFromFile("Textures/Player1.png"))
	{
		playerTexture.setSmooth(false);
		playerTexture.setRepeated(false);

		playerSprite.setTexture(playerTexture);
	}
}

Sprite& Player::getSprite()
{
	return playerSprite;
}

FloatRect Player::getPosition()
{
	return playerSprite.getGlobalBounds();
}

float Player::getLanePosition()
{
	float xPosition = 0;

	switch (lanePosition)
	{
	case 0:
		xPosition =  1024 / 5 - 28;
		break;
	case 1:
		xPosition = 1024 / 5 * 2 - 28;
		break;
	case 2:
		xPosition = 1024 / 5 * 3 - 28;
		break;
	case 3:
		xPosition = 1024 / 5 * 4 - 28;
		break;
	}

	return xPosition;
}

void Player::moveLeft()
{
	if (lanePosition >= 1)
		lanePosition--;

	position.x = getLanePosition();
	//position.x -= playerSpeed;
}

void Player::moveRight()
{
	if (lanePosition <= 2)
		lanePosition++;

	position.x = getLanePosition();
	//position.x += playerSpeed;
}

void Player::update()
{
	playerSprite.setPosition(position);
}