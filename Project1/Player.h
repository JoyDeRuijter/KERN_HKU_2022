#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	private:
		Vector2f position;
		RectangleShape playerShape;
		float playerSpeed = .3f;

	public:
		Player(float startX, float startY);
		FloatRect getPosition();
		RectangleShape& getShape();
		void moveLeft();
		void moveRight();
		void update();
};

