#include "GameManager.h"
#include "Player.h"
#include "CarNPC.h"
#include <sstream>
#include <iostream>

using namespace sf;

//GameManager::GameManager()
//{
//	initializeRenderWindow();
//	initializePlayer();
//	initializeFont();
//
//	setHud();
//	manageAmountOfCarNPCs();
//	manageAmountOfPedestrians();
//}
//
//void GameManager::draw()
//{
//	drawBackground();
//	drawHud();
//	drawCarNPCs();
//	drawPedestrians();
//	drawPlayer();
//}
//
//void GameManager::update()
//{
//	checkCollisions();
//	updateCarNPCs();
//	updatePedestrians();
//	updatePlayer();
//}
//
//void GameManager::initializeRenderWindow()
//{
//	windowWidth = 1024;
//	windowHeight = 768;
//
//	if (backgroundTexture.loadFromFile("Textures/Road.png"))
//	{
//		backgroundTexture.setSmooth(false);
//		backgroundTexture.setRepeated(false);
//
//		backgroundSprite.setTexture(backgroundTexture);
//	}
//
//	window.create(VideoMode(windowWidth, windowHeight), "Speed Racer - Joy de Ruijter");
//}
//
//RenderWindow& GameManager::getRenderWindow()
//{
//	return window;
//}
//
//void GameManager::drawBackground()
//{
//	window.draw(backgroundSprite);
//}
//
//void GameManager::deleteCarNPC(CarNPC* carNPC)
//{
//	carNPCs.erase(std::remove(carNPCs.begin(), carNPCs.end(), carNPC), carNPCs.end());
//	manageAmountOfCarNPCs();
//}
//
//void GameManager::addCarNPC()
//{
//	CarNPC* carNPC = new CarNPC();
//	carNPC->initializeLanePositions();
//	carNPCs.push_back(carNPC);
//}
//
//void GameManager::updateCarNPCs()
//{
//	for (int i = 0; i < carNPCs.size(); i++)
//		carNPCs[i]->update();
//}
//
//void GameManager::drawCarNPCs()
//{
//	for (int i = 0; i < carNPCs.size(); i++)
//		window.draw(carNPCs[i]->getSprite());
//}
//
//void GameManager::manageAmountOfCarNPCs()
//{
//	while (carNPCs.size() < carNPCAmount)
//		addCarNPC();
//}
//
//void GameManager::deletePedestrian(Pedestrian* pedestrian)
//{
//	pedestrians.erase(std::remove(pedestrians.begin(), pedestrians.end(), pedestrian), pedestrians.end());
//	manageAmountOfPedestrians();
//}
//
//void GameManager::addPedestrian()
//{
//	Pedestrian* pedestrian = new Pedestrian();
//	//pedestrian->initializeLanePositions(); change this into a function that determines the direction and start x
//	pedestrians.push_back(pedestrian);
//}
//
//void GameManager::updatePedestrians()
//{
//	for (int i = 0; i < pedestrians.size(); i++)
//		pedestrians[i]->update();
//}
//
//void GameManager::drawPedestrians()
//{
//	for (int i = 0; i < pedestrians.size(); i++)
//		window.draw(pedestrians[i]->getSprite());
//}
//
//void GameManager::manageAmountOfPedestrians()
//{
//	while (pedestrians.size() < pedestrianAmount)
//		addPedestrian();
//}
//
//void GameManager::checkCollisions()
//{
//	for (int i = 0; i < carNPCs.size(); i++)
//	{
//		if (carNPCs[i]->getPosition().top > windowHeight)
//		{
//			deleteCarNPC(carNPCs[i]);
//			addScore();
//		}
//
//		if (carNPCs[i]->rigidbody.collider->isTouching(player->rigidbody.collider))
//		{
//			reduceLives();
//			deleteCarNPC(carNPCs[i]);
//		}
//	}
//}
//
//void GameManager::initializePlayer()
//{
//	player = new CarPlayer();
//}
//
//void GameManager::updatePlayer()
//{
//	player->update();
//}
//
//void GameManager::drawPlayer()
//{
//	window.draw(player->getSprite());
//}
//
//void GameManager::initializeFont()
//{
//	if (font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
//	{
//		hud.setFont(font);
//		hud.setCharacterSize(60);
//		hud.setFillColor(Color::White);
//		hud.setPosition(10,10);
//	}
//}
//
//void GameManager::setHud()
//{
//	std::stringstream ss;
//	ss << "Score: " << score << "   Lives: " << lives;
//	hud.setString(ss.str());
//}
//
//void GameManager::drawHud()
//{
//	window.draw(hud);
//}
//
//void GameManager::addScore()
//{
//	score++;
//	setHud();
//}
//
//void GameManager::reduceLives()
//{
//	if (lives - 1 > 0)
//	{
//		lives--;
//		setHud();
//		return;
//	}
//	else
//		gameOver();
//}
//
//void GameManager::gameOver()
//{
//	gameIsOver = true;
//
//	std::stringstream ss;
//	ss << "GAME OVER";
//	hud.setString(ss.str());
//
//	window.clear(Color(0, 0, 0, 255));
//}

GameManager::GameManager()
{
	windowWidth = 960;
	windowHeight = 800;
	multiplier = 10;
	lives = 3;
	score = 0;

	player = new CarPlayer(windowWidth/2, windowHeight - 140, 0);

	if (!backgroundText.loadFromFile("Textures/Achtergrond.png")) {
		cout << "Could not load texture" << endl;
		return;
	}
	background.setTexture(backgroundText);
}

void GameManager::start()
{
	initializeGame();
}

void GameManager::update(float _time)
{
	Event event;
	while (GetWindow().pollEvent(event))
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
			player->moveLeft();
		else if (Keyboard::isKeyPressed(Keyboard::Right))
			player->moveRight();
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
			GetWindow().close();
		else if (event.type == Event::KeyReleased)
		{
			if (event.key.code == Keyboard::Left)
			{
				player->rigidbody->forceSideways = player->rigidbody->addForce(player->rigidbody->forceSideways, 1) * _time;
				if (player->rigidbody->forceSideways <= 0)
					player->rigidbody->forceSideways = 0;
			}
			if (event.key.code == Keyboard::Right)
			{
				player->rigidbody->forceSideways = player->rigidbody->addForce(player->rigidbody->forceSideways, -1) * _time;
				if (player->rigidbody->forceSideways <= 0)
					player->rigidbody->forceSideways = 0;
			}
		}
	}

	if (isStillPlaying())
	{
		player->update(_time);
		manageCarNPCs(_time);
		scrollingBackground();
		draw();
	}
	else
		displayEndScreen();
}

void GameManager::draw()
{
	GetWindow().clear(Color(0, 0, 0, 255));

	window.draw(background);
	drawRoadusers();
	displayScore();
	GetWindow().display();
}

void GameManager::initializeGame()
{
	window.create(VideoMode(windowWidth, windowHeight), "Joy de Ruijter - Kernmodule GDEV");
	background.setPosition(0, -windowHeight);
}

void GameManager::scrollingBackground()
{
	Vector2D backgroundPosition = Vector2D(background.getPosition().x, background.getPosition().y);
	player->rigidbody->forceForward = player->rigidbody->addForce(player->rigidbody->forceForward, multiplier);
	backgroundPosition.y += player->rigidbody->calculateVelocity(player->rigidbody->yVelocity, player->rigidbody->mass, player->rigidbody->forceForward, time);
	background.setPosition(Vector2f(backgroundPosition.x, backgroundPosition.y));
	if (backgroundPosition.y >= 0)
		background.setPosition(0, -windowHeight);
}

void GameManager::drawRoadusers()
{
	window.draw(player->getSprite());
	for (int i = 0; i < carNPCs.size(); i++)
		window.draw(carNPCs[i]->getSprite());

	//add pedestrians here
}

void GameManager::spawnCarNPCs()
{
	CarNPC* carNPC = new CarNPC(0, 0, 70 + multiplier);
	carNPCs.push_back(carNPC);
}

void GameManager::manageCarNPCs(float _time)
{
	float amountOfCarNPCs = 1;
	while (carNPCs.size() < amountOfCarNPCs)
		spawnCarNPCs();

	for (int i = 0; i < carNPCs.size(); i++)
	{
		carNPCs[i]->update(_time);
		if (carNPCs[i]->getPosition().top > windowHeight)
		{
			updateMultiplier();
			score++;
			deleteCarNPC(carNPCs[i]);
			return;
		}

		if (carNPCs[i]->getPosition().isTouching(player->getPosition()))
		{
			lives--;
			deleteCarNPC(carNPCs[i]);
			return;
		}
	}
}

void GameManager::deleteCarNPC(CarNPC* _carNPC)
{
	carNPCs.erase(remove(carNPCs.begin(), carNPCs.end(), _carNPC), carNPCs.end());
}

void GameManager::updateMultiplier()
{
	multiplier += 20;
}

void GameManager::displayScore()
{
	RectangleShape bg;
	bg.setFillColor(Color::Black);
	bg.setSize(Vector2f(windowWidth, 60));

	Font font;
	if (!font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
	{
		cout << "Could not load font" << endl;
		return;
	}
	Text livesText;
	livesText.setFont(font);
	livesText.setCharacterSize(50);
	livesText.setPosition(20, 0);
	livesText.setFillColor(sf::Color::White);
	livesText.setString("lives: " + to_string(lives));

	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setPosition(480, 0);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("score: " + to_string(score));

	window.draw(bg);
	window.draw(livesText);
	window.draw(scoreText);
}

void GameManager::displayEndScreen()
{
	GetWindow().clear(Color::Black);
	Font font;
	if (!font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
	{
		cout << "Could not load font" << endl;
		return;
	}
	Text gameoverText;
	gameoverText.setFont(font);
	gameoverText.setOrigin(175, 75 / 2);
	gameoverText.setPosition(Vector2f((windowWidth / 2) - 30, (windowHeight / 2) - 75));
	gameoverText.setCharacterSize(75);
	gameoverText.setFillColor(sf::Color::Red);
	gameoverText.setString("GAME OVER");

	Text scoreText;
	scoreText.setFont(font);
	scoreText.setOrigin(175, 75 / 2);
	scoreText.setPosition(Vector2f((windowWidth / 2) - 30, (windowHeight / 2)));
	scoreText.setCharacterSize(75);
	scoreText.setFillColor(sf::Color::Red);
	scoreText.setString("end score: " + to_string(score));

	window.draw(scoreText);
	window.draw(gameoverText);
	GetWindow().display();
}

bool GameManager::isStillPlaying()
{
	if (lives <= 0)
		return false;

	return true;
}

RenderWindow& GameManager::GetWindow()
{
	return window;
}