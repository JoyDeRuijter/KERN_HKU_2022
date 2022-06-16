#include "Pedestrian.h"

Pedestrian::Pedestrian() : Roaduser()
{
	position = Vector2D(500, 500);
	texturePath = "Textures/Pedestrian.png";
	rigidbody = Rigidbody(position, 1, 57, 42, 0.8f);
	initializeTextureAndSprite();
}

void Pedestrian::update()
{
	Roaduser::update();
}