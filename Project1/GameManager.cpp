#include "GameManager.h"
#include <sstream>
#include <iostream>

GameManager::GameManager(){}

void GameManager::InitializeRenderWindow()
{
	windowWidth = 1024;
	windowHeight = 768;

	if (backgroundTexture.loadFromFile("Textures/Road.png"))
	{
		backgroundTexture.setSmooth(false);
		backgroundTexture.setRepeated(false);

		backgroundSprite.setTexture(backgroundTexture);
	}

	window.create(VideoMode(windowWidth, windowHeight), "Speed Racer - Joy de Ruijter");
}

RenderWindow& GameManager::GetRenderWindow()
{
	return window;
}

void GameManager::DrawBackground()
{
	window.draw(backgroundSprite);
}

void GameManager::DeleteCar(Car* car)
{
	cars.erase(std::remove(cars.begin(), cars.end(), car), cars.end());
	ManageAmountOfCars();
}

void GameManager::AddCar()
{
	Car* car = new Car(0);
	car->InitializeTextureAndSprite();
	car->setXPosition(car->getXPosition(1024));
	cars.push_back(car);
}

void GameManager::UpdateCars()
{
	for (int i = 0; i < cars.size(); i++)
		cars[i]->update();
}

void GameManager::DrawCars()
{
	for (int i = 0; i < cars.size(); i++)
		window.draw(cars[i]->getSprite());
}

void GameManager::ManageAmountOfCars()
{
	while (cars.size() < carAmount)
		AddCar();
}

void GameManager::CheckCarCollisions()
{
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i]->getPosition().top > windowHeight)
		{
			DeleteCar(cars[i]);
			AddScore();
		}

		if (cars[i]->getPosition().intersects(player.getPosition()))
		{
			ReduceLives();
			DeleteCar(cars[i]);
		}
	}
}

void GameManager::InitializePlayer()
{
	player = Player(1);
	player.InitializeTextureAndSprite();
}

void GameManager::UpdatePlayer()
{
	player.update();
}

void GameManager::DrawPlayer()
{
	window.draw(player.getSprite());
}

void GameManager::InitializeFont()
{
	if (font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
	{
		hud.setFont(font);
		hud.setCharacterSize(60);
		hud.setFillColor(Color::White);
		hud.setPosition(10,10);
	}
}

void GameManager::SetHud()
{
	std::stringstream ss;
	ss << "Score: " << score << "   Lives: " << lives;
	hud.setString(ss.str());
}

void GameManager::DrawHud()
{
	window.draw(hud);
}

void GameManager::AddScore()
{
	score++;
	SetHud();
}

void GameManager::ReduceLives()
{
	if (lives-- > 0)
	{
		lives--;
		SetHud();
		return;
	}
	else
		GameOver();
}

void GameManager::GameOver()
{
	gameIsOver = true;

	std::stringstream ss;
	ss << "GAME OVER";
	hud.setString(ss.str());

	window.clear(Color(0, 0, 0, 255));
}
