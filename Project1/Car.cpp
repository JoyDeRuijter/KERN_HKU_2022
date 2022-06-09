#include "Car.h"
#include <iostream>

Car::Car(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	carShape.setSize(sf::Vector2f(75, 100));
	carShape.setPosition(position);
}

FloatRect Car::getPosition()
{
	return carShape.getGlobalBounds();
}

RectangleShape& Car::getShape()
{
	return carShape;
}

float Car::getXPosition(int windowWidth)
{
	float xPosition;
	lanePosition = rand() % 4;

	switch(lanePosition)
	{
		case 0:
			xPosition = windowWidth/5;
			break;
		case 1:
			xPosition = windowWidth/5 * 2;
			break;
		case 2:
			xPosition = windowWidth/5 * 3;
			break;
		case 3:
			xPosition = windowWidth/5 *4;
			break;
	}
	return xPosition;
}

void Car::setXPosition(float xPosition)
{
	position.x = xPosition;
}

void Car::reboundSides()
{
	xVelocity = -xVelocity;
}

void Car::reboundPlayerOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Car::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Car::update()
{
	position.y += yVelocity;
	position.x += xVelocity;

	carShape.setPosition(position);
}