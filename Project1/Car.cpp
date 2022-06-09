#include "Car.h"
#include <iostream>

Car::Car(float startX)
{
	position.x = startX;
	position.y = 90;
}

void Car::InitializeTextureAndSprite()
{
	if (carTexture.loadFromFile("Textures/Player2.png"))
	{
		carTexture.setSmooth(false);
		carTexture.setRepeated(false);

		carSprite.setTexture(carTexture);
	}
}


FloatRect Car::getPosition()
{
	return carSprite.getGlobalBounds();
}

Sprite& Car::getSprite()
{
	return carSprite;
}

float Car::getXPosition(int windowWidth)
{
	float xPosition = 0;
	lanePosition = rand() % 4;

	switch(lanePosition)
	{
		case 0:
			xPosition = 1024 / 5 - 28;
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

void Car::setXPosition(float xPosition)
{
	position.x = xPosition;
}

void Car::update()
{
	position.y += yVelocity;
	position.x += xVelocity;

	carSprite.setPosition(position);
}