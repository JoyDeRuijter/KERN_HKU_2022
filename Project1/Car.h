#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Car
{
	private:
		Vector2f position;
		Texture carTexture;
		Sprite carSprite;

		float xVelocity = 0;
		float yVelocity = .4f;
		int lanePosition = 0;

	public:
		Car(float startX);

		void InitializeTextureAndSprite();

		FloatRect getPosition();
		Sprite& getSprite();
		float getXPosition(int windowWidth);
		void setXPosition(float xPosition);
		void update();
};

