#pragma once
#include <Vector>
#include "Car.h"
#include "Player.h"

using namespace sf;

class GameManager
{
	private:
		std::vector<Car*> cars;
		int carAmount = 2;
		
		int score = 0;
		int lives = 50;
		Text hud;
		Font font;

		Texture backgroundTexture;
		Sprite backgroundSprite;
		RenderWindow window;

	public:
		GameManager();

		bool gameIsOver = false;

		int windowHeight = 0;
		int windowWidth = 0;
		void InitializeRenderWindow();
		RenderWindow& GetRenderWindow();
		void DrawBackground();

		void DeleteCar(Car* car);
		void AddCar();
		void UpdateCars();
		void DrawCars();
		void ManageAmountOfCars();
		void CheckCarCollisions();

		Player player = Player(1);
		void InitializePlayer();
		void UpdatePlayer();
		void DrawPlayer();

		void InitializeFont();
		void SetHud();
		void DrawHud();
		void AddScore();
		void ReduceLives();
		void GameOver();
};

