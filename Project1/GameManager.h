#pragma once
#include <Vector>
#include "Roaduser.h"
#include "Car.h"
#include "CarNPC.h"
#include "CarPlayer.h"

using namespace sf;

class GameManager
{
	private:
		std::vector<CarNPC*> carNPCs;
		int carNPCAmount = 2;
		
		int score = 0;
		int lives = 50;
		Text hud;
		Font font;

		Texture backgroundTexture;
		Sprite backgroundSprite;
		RenderWindow window;

	public:
		GameManager();

		void draw();
		void update();

		bool gameIsOver = false;

		int windowHeight = 0;
		int windowWidth = 0;
		void initializeRenderWindow();
		RenderWindow& getRenderWindow();
		void drawBackground();
		void deleteCarNPC(CarNPC* carNPC);
		void addCarNPC();
		void updateCarNPCs();
		void drawCarNPCs();
		void manageAmountOfCarNPCs();
		void checkCollisions();
		CarPlayer* player;
		void initializePlayer();
		void updatePlayer();
		void drawPlayer();

		void initializeFont();
		void setHud();
		void drawHud();
		void addScore();
		void reduceLives();
		void gameOver();
};

