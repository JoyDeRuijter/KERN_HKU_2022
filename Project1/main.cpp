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

    while (gameManager.getRenderWindow().isOpen())
    {
        Event event;
        while (gameManager.getRenderWindow().pollEvent(event))
        {
            if (event.type == Event::Closed)
                gameManager.getRenderWindow().close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left && !gameManager.gameIsOver)
                    gameManager.player->moveLeft();

                else if (event.key.code == sf::Keyboard::Right && !gameManager.gameIsOver)
                    gameManager.player->moveRight();

                else if (Keyboard::isKeyPressed(Keyboard::Escape))
                    gameManager.getRenderWindow().close();
            }
        }

        if (gameManager.gameIsOver)
            continue;

        gameManager.update();

        gameManager.getRenderWindow().clear(Color(26, 128, 182, 255));
        
        gameManager.draw();

        gameManager.getRenderWindow().display();
    }
    return 0;
}