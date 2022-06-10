#include "CarNPC.h"

CarNPC::CarNPC() : Car()
{
	position.x = getStartLane();
	position.y = 90;
	texturePath = "Textures/Player2.png";
	initializeTextureAndSprite();
}

float CarNPC::getStartLane()
{
	startLane = rand() % 4;
	currentLane = startLane;
	return lanePositions[currentLane];
}

void CarNPC::update()
{
	Roaduser::update();
	position.y += yVelocity;
}