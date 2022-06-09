#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Car.h"
#include "GameManager.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

int main()
{
    GameManager gameManager;

    
    gameManager.InitializeRenderWindow();
    gameManager.InitializePlayer();
    gameManager.InitializeFont();

    gameManager.SetHud();
    gameManager.ManageAmountOfCars();

    while (gameManager.GetRenderWindow().isOpen())
    {
        Event event;
        while (gameManager.GetRenderWindow().pollEvent(event))
        {
            if (event.type == Event::Closed)
                gameManager.GetRenderWindow().close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left && !gameManager.gameIsOver)
                    gameManager.player.moveLeft();

                else if (event.key.code == sf::Keyboard::Right && !gameManager.gameIsOver)
                    gameManager.player.moveRight();

                else if (Keyboard::isKeyPressed(Keyboard::Escape))
                    gameManager.GetRenderWindow().close();
            }
        }

        if (gameManager.gameIsOver)
            continue;

        gameManager.CheckCarCollisions();

        gameManager.UpdateCars();
        gameManager.UpdatePlayer();

        gameManager.GetRenderWindow().clear(Color(26, 128, 182, 255));
        gameManager.DrawBackground();
        gameManager.DrawHud();
        gameManager.DrawCars();
        gameManager.DrawPlayer();
        gameManager.GetRenderWindow().display();
    }
    return 0;
}