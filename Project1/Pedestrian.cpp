#include "Pedestrian.h"

Pedestrian::Pedestrian() : Roaduser()
{
	position.x = 500;
	position.y = 500;
	texturePath = "Textures/Pedestrian.png";
	initializeTextureAndSprite();
}

void Pedestrian::update()
{
	Roaduser::update();
}