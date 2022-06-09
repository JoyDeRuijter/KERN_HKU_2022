#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Car
{
	private:
		Vector2f position;
		RectangleShape carShape;

		float xVelocity = 0;
		float yVelocity = .5f;
		int lanePosition;

	public:
		Car(float startX, float startY);
		FloatRect getPosition();
		RectangleShape& getShape();
		float getXPosition(int windowWidth);
		void setXPosition(float xPosition);
		void reboundSides();
		void reboundPlayerOrTop();
		void hitBottom();
		void update();
};

