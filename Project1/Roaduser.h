#pragma once
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
using namespace sf;

class Rigidbody;

class Roaduser
{
	private:
		Texture roaduserTexture;

	protected:
		float xVelocity = .2f;
		float yVelocity = .2f;
		Vector2D position;
		Sprite roaduserSprite;
		String texturePath;

	public:
		Roaduser();
		Rigidbody rigidbody;
		void initializeTextureAndSprite();
		FloatRect getPosition();
		Sprite& getSprite();
		virtual void update();
};

