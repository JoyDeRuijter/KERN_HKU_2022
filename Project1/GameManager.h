// Joy de Ruijter - 2022

#pragma once
#include <Vector>
#include <SFML/Graphics.hpp>
#include "Roaduser.h"
#include "CarNPC.h"
#include "CarPlayer.h"

using namespace sf;

class GameManager
{
	private:
		float multiplier;
		CarPlayer* player;
		std::vector<CarNPC*> carNPCs;

		// Render Window variables
		int windowWidth;
		int windowHeight;
		RenderWindow window;
		Sprite background;
		Texture backgroundTexture;

		// HUD variables
		Font font;
		Text scoreText;
		Text livesText;
		Text gameoverText;
		int lives;
		int score;

	public:
		GameManager();

		float time;

		void start();
		void update(float _time);
		void draw();
		void backgroundScrolling();
		void drawRoadusers();
		void initializePlayer();
		void initializeBackground();
		void addCarNPC();
		void manageCarNPCs();
		void deleteCarNPC(CarNPC* _carNPC);
		void updateCarNPCs(float _time);
		void checkCollisions();
		
		void updateMultiplier();
		
		void addScore();
		void reduceLives();
		void initializeFont();
		void displayScore();
		void displayEndScreen();

		bool isStillPlaying();
		RenderWindow& GetWindow();
};

