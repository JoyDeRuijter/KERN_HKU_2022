#include "Player.h"

Player::Player(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	playerShape.setSize(sf::Vector2f(75, 100));
	playerShape.setPosition(position);
}

RectangleShape& Player::getShape()
{
	return playerShape;
}

FloatRect Player::getPosition()
{
	return playerShape.getGlobalBounds();
}

void Player::moveLeft()
{
	position.x -= playerSpeed;
}

void Player::moveRight()
{
	position.x += playerSpeed;
}

void Player::update()
{
	playerShape.setPosition(position);
}