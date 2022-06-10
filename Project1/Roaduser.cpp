#include "Roaduser.h"
using namespace sf;

Roaduser::Roaduser(){}

void Roaduser::initializeTextureAndSprite()
{
	if (roaduserTexture.loadFromFile(texturePath))
	{
		roaduserTexture.setSmooth(false);
		roaduserTexture.setRepeated(false);

		roaduserSprite.setTexture(roaduserTexture);
	}
}

FloatRect Roaduser::getPosition()
{
	return roaduserSprite.getGlobalBounds();
}

Sprite& Roaduser::getSprite()
{
	return roaduserSprite;
}

void Roaduser::update()
{
	roaduserSprite.setPosition(position);
}