#include "GameManager.h"
#include <sstream>
#include <iostream>

GameManager::GameManager()
{
	initializeRenderWindow();
	initializePlayer();
	initializeFont();

	setHud();
	manageAmountOfCarNPCs();
	manageAmountOfPedestrians();
}

void GameManager::draw()
{
	drawBackground();
	drawHud();
	drawCarNPCs();
	drawPedestrians();
	drawPlayer();
}

void GameManager::update()
{
	checkCollisions();
	updateCarNPCs();
	updatePedestrians();
	updatePlayer();
}

void GameManager::initializeRenderWindow()
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

RenderWindow& GameManager::getRenderWindow()
{
	return window;
}

void GameManager::drawBackground()
{
	window.draw(backgroundSprite);
}

void GameManager::deleteCarNPC(CarNPC* carNPC)
{
	carNPCs.erase(std::remove(carNPCs.begin(), carNPCs.end(), carNPC), carNPCs.end());
	manageAmountOfCarNPCs();
}

void GameManager::addCarNPC()
{
	CarNPC* carNPC = new CarNPC();
	carNPC->initializeLanePositions();
	carNPCs.push_back(carNPC);
}

void GameManager::updateCarNPCs()
{
	for (int i = 0; i < carNPCs.size(); i++)
		carNPCs[i]->update();
}

void GameManager::drawCarNPCs()
{
	for (int i = 0; i < carNPCs.size(); i++)
		window.draw(carNPCs[i]->getSprite());
}

void GameManager::manageAmountOfCarNPCs()
{
	while (carNPCs.size() < carNPCAmount)
		addCarNPC();
}

void GameManager::deletePedestrian(Pedestrian* pedestrian)
{
	pedestrians.erase(std::remove(pedestrians.begin(), pedestrians.end(), pedestrian), pedestrians.end());
	manageAmountOfPedestrians();
}

void GameManager::addPedestrian()
{
	Pedestrian* pedestrian = new Pedestrian();
	//pedestrian->initializeLanePositions(); change this into a function that determines the direction and start x
	pedestrians.push_back(pedestrian);
}

void GameManager::updatePedestrians()
{
	for (int i = 0; i < pedestrians.size(); i++)
		pedestrians[i]->update();
}

void GameManager::drawPedestrians()
{
	for (int i = 0; i < pedestrians.size(); i++)
		window.draw(pedestrians[i]->getSprite());
}

void GameManager::manageAmountOfPedestrians()
{
	while (pedestrians.size() < pedestrianAmount)
		addPedestrian();
}

void GameManager::checkCollisions()
{
	for (int i = 0; i < carNPCs.size(); i++)
	{
		if (carNPCs[i]->getPosition().top > windowHeight)
		{
			deleteCarNPC(carNPCs[i]);
			addScore();
		}

		if (carNPCs[i]->getPosition().intersects(player->getPosition()))
		{
			reduceLives();
			deleteCarNPC(carNPCs[i]);
		}
	}
}

void GameManager::initializePlayer()
{
	player = new CarPlayer();
}

void GameManager::updatePlayer()
{
	player->update();
}

void GameManager::drawPlayer()
{
	window.draw(player->getSprite());
}

void GameManager::initializeFont()
{
	if (font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
	{
		hud.setFont(font);
		hud.setCharacterSize(60);
		hud.setFillColor(Color::White);
		hud.setPosition(10,10);
	}
}

void GameManager::setHud()
{
	std::stringstream ss;
	ss << "Score: " << score << "   Lives: " << lives;
	hud.setString(ss.str());
}

void GameManager::drawHud()
{
	window.draw(hud);
}

void GameManager::addScore()
{
	score++;
	setHud();
}

void GameManager::reduceLives()
{
	if (lives - 1 > 0)
	{
		lives--;
		setHud();
		return;
	}
	else
		gameOver();
}

void GameManager::gameOver()
{
	gameIsOver = true;

	std::stringstream ss;
	ss << "GAME OVER";
	hud.setString(ss.str());

	window.clear(Color(0, 0, 0, 255));
}
