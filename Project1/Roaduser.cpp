// Joy de Ruijter - 2022

#include "Roaduser.h"
using namespace sf;

Roaduser::Roaduser(){}

Roaduser::Roaduser(float _startX, float _startY, float _force){}

void Roaduser::initializeTextureAndSprite()
{
	if (roaduserTexture.loadFromFile(texturePath))
	{
		roaduserTexture.setSmooth(false);
		roaduserTexture.setRepeated(false);

		roaduserSprite.setTexture(roaduserTexture);
	}
}

Collider Roaduser::getPosition()
{
	return Collider(Vector2D(position), Vector2D(size));
}

Sprite& Roaduser::getSprite()
{
	return roaduserSprite;
}