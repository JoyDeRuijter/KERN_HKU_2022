#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	private:
		Vector2f position;
		//RectangleShape playerShape;
		float playerSpeed = .3f;
		int lanePosition = 1;

		Texture playerTexture;
		Sprite playerSprite;

	public:
		Player(int startLane);

		void InitializeTextureAndSprite();

		FloatRect getPosition();
		Sprite& getSprite();
		void moveLeft();
		void moveRight();
		float getLanePosition();
		void update();

		bool leftKeyIsPressed = false;
		bool rightKeyIsPressed = false;
};

