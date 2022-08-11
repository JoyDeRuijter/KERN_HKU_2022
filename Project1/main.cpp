#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameManager.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

int main()
{
    srand(time(0));

    Clock deltaClock;

    GameManager gamemanager;
    gamemanager.start();

    while (gamemanager.GetWindow().isOpen())
    {
        float dt = deltaClock.restart().asSeconds();

        gamemanager.update(dt);
    }
}