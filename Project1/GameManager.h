#pragma once
#include <Vector>
#include "Roaduser.h"
#include "Car.h"
#include "CarNPC.h"
#include "CarPlayer.h"
#include "Pedestrian.h"

using namespace sf;

class GameManager
{
	private:
		std::vector<CarNPC*> carNPCs;
		int carNPCAmount = 2;

		std::vector<Pedestrian*> pedestrians;
		int pedestrianAmount = 1;
		
		int score = 0;
		int lives = 12;
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

		void deletePedestrian(Pedestrian* pedestrian);
		void addPedestrian();
		void updatePedestrians();
		void drawPedestrians();
		void manageAmountOfPedestrians();

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

