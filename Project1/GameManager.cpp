// Joy de Ruijter - 2022

#include "GameManager.h"
#include "Player.h"
#include "CarNPC.h"
#include <sstream>
#include <iostream>

using namespace sf;

GameManager::GameManager()
{
	lives = 3;
	score = 0;
	multiplier = 10;
}

void GameManager::start()
{
	initializeBackground();
	initializePlayer();
	initializeFont();
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
		manageCarNPCs();
		updateCarNPCs(_time);
		checkCollisions();
		backgroundScrolling();
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

void GameManager::initializePlayer()
{
	player = new CarPlayer(windowWidth / 2, windowHeight - 140, 0);
}

void GameManager::initializeBackground()
{
	windowWidth = 960;
	windowHeight = 800;

	if (backgroundTexture.loadFromFile("Textures/Achtergrond.png"))
	{
		backgroundTexture.setSmooth(false);
		backgroundTexture.setRepeated(false);
		background.setTexture(backgroundTexture);
	}

	window.create(VideoMode(windowWidth, windowHeight), "Speed Racer - Joy de Ruijter");
	background.setPosition(0, -windowHeight);
}

RenderWindow& GameManager::GetWindow()
{
	return window;
}

void GameManager::backgroundScrolling() // Handle the scrolling of the background image
{
	Vector2D backgroundPosition = Vector2D(background.getPosition().x, background.getPosition().y);
	player->rigidbody->forceForward = player->rigidbody->addForce(player->rigidbody->forceForward, multiplier);
	backgroundPosition.y += player->rigidbody->calculateVelocity(player->rigidbody->yVelocity, player->rigidbody->mass, player->rigidbody->forceForward, time);
	background.setPosition(Vector2f(backgroundPosition.x, backgroundPosition.y));
	if (backgroundPosition.y >= 0)
		background.setPosition(0, -windowHeight);
}

void GameManager::drawRoadusers() // Draw all roadusers on the screen
{
	// Draw player
	window.draw(player->getSprite());

	// Draw car NPCs
	for (int i = 0; i < carNPCs.size(); i++)
		window.draw(carNPCs[i]->getSprite());
}

void GameManager::addCarNPC() // Add new carNPC to list of carNPCs
{
	CarNPC* carNPC = new CarNPC(0, 0, 75 + multiplier);
	carNPCs.push_back(carNPC);
}

void GameManager::manageCarNPCs() // Make sure there is always one carNPC in the screen
{
	while (carNPCs.size() < 1)
		addCarNPC();
}

void GameManager::updateCarNPCs(float _time) // Updates all carNPCs in the list
{
	for (int i = 0; i < carNPCs.size(); i++)
		carNPCs[i]->update(_time);
}

void GameManager::checkCollisions() // Checks all collisions between carNPCs and the player, and between carNPCs and the end of the screen
{
	for (int i = 0; i < carNPCs.size(); i++)
	{
		if (carNPCs[i]->getPosition().top > windowHeight)
		{
			deleteCarNPC(carNPCs[i]);
			addScore();
			return;
		}

		if (carNPCs[i]->getPosition().isTouching(player->getPosition()))
		{
			reduceLives();
			deleteCarNPC(carNPCs[i]);
			return;
		}
	}
}

void GameManager::deleteCarNPC(CarNPC* _carNPC) // Delete the given carNPC from the list of carNPCs
{
	carNPCs.erase(remove(carNPCs.begin(), carNPCs.end(), _carNPC), carNPCs.end());
	updateMultiplier();
}

void GameManager::updateMultiplier() // Increase the game multiplier
{
	multiplier += 20;
}

void GameManager::addScore() // Increase the score
{
	score++;
}

void GameManager::reduceLives() // Decrease the lives
{
	lives--;
}

void GameManager::initializeFont()
{
	if (font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
	{
		livesText.setFont(font);
		scoreText.setFont(font);
		gameoverText.setFont(font);
	}
}

void GameManager::displayScore() // Create and display the top hud-bar that shows the lives and score counters
{
	RectangleShape bg;
	bg.setFillColor(Color::Black);
	bg.setSize(Vector2f(windowWidth, 60));

	livesText.setCharacterSize(50);
	livesText.setPosition(20, 0);
	livesText.setFillColor(sf::Color::White);
	livesText.setString("lives: " + to_string(lives));

	scoreText.setCharacterSize(50);
	scoreText.setPosition(770, 0);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("score: " + to_string(score));

	window.draw(bg);
	window.draw(livesText);
	window.draw(scoreText);
}

void GameManager::displayEndScreen() // Create and display the endscreen with the game over text and final score
{
	GetWindow().clear(Color::Black);
	
	gameoverText.setOrigin(175, 75 / 2);
	gameoverText.setPosition(Vector2f((windowWidth / 2) - 30, (windowHeight / 2) - 75));
	gameoverText.setCharacterSize(75);
	gameoverText.setFillColor(sf::Color::White);
	gameoverText.setString("GAME OVER");

	scoreText.setOrigin(175, 75 / 2);
	scoreText.setPosition(Vector2f((windowWidth / 2) - 30, (windowHeight / 2 + 75)));
	scoreText.setCharacterSize(75);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("end score: " + to_string(score));

	window.draw(scoreText);
	window.draw(gameoverText);
	GetWindow().display();
}

bool GameManager::isStillPlaying() // Returns true when the player has more than zero lives, otherwise returns false
{
	if (lives <= 0)
		return false;

	return true;
}

