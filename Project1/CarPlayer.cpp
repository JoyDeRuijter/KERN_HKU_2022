#include "CarPlayer.h"

CarPlayer::CarPlayer() : Car()
{
	startLane = 1;
	currentLane = startLane;
	position = Vector2D(getLanePosition(), 648);
	texturePath = "Textures/Player1.png";
	initializeTextureAndSprite();
}

float CarPlayer::getLanePosition()
{
	return lanePositions[currentLane];
}

void CarPlayer::moveLeft()
{
	if (currentLane >= 1)
		currentLane--;

	position.x = getLanePosition();
}

void CarPlayer::moveRight()
{
	if (currentLane <= 2)
		currentLane++;

	position.x = getLanePosition();
}