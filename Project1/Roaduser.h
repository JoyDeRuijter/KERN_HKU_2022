#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2D.h"
#include "Collider.h"

using namespace sf;

class Roaduser
{
	private:
		Texture roaduserTexture;

	protected:
		Vector2D size;
		Sprite roaduserSprite;
		String texturePath;

	public:
		Roaduser();
		Roaduser(float _startX, float _startY, float _force);

		Rigidbody* rigidbody;
		Vector2D position;

		void initializeTextureAndSprite();
		Collider getPosition();
		Sprite& getSprite();
};

