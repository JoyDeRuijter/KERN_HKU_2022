#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Roaduser
{
	private:
		Texture roaduserTexture;

	protected:
		float xVelocity = .2f;
		float yVelocity = .2f;
		Vector2f position;
		Sprite roaduserSprite;
		String texturePath;

	public:
		Roaduser();

		void initializeTextureAndSprite();
		FloatRect getPosition();
		Sprite& getSprite();
		virtual void update();
};

