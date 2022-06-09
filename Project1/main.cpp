#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Car.h"
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace sf;

int main()
{
    int windowWidth = 1024;
    int windowHeight = 768;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Speed Racer");
    
    int score = 0;
    int lives = 3;

    Player player (windowWidth / 2, windowHeight - 120);
    Car car (0 , 100);
    car.setXPosition(car.getXPosition(windowWidth));

    Text hud;
    Font font;
    if (font.loadFromFile("Fonts/Open24DisplaySt.ttf"))
    {
        std::cout << "nou hij doet het hoor" << std::endl;
        hud.setFont(font);
        hud.setCharacterSize(60);
        hud.setFillColor(Color::White);
    }


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.moveRight();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (car.getPosition().top > windowHeight)
        {
            car.hitBottom();
            score++;
        }

        if (car.getPosition().top < 0)
        {
            car.reboundPlayerOrTop();   
        }

        if (car.getPosition().left < 0 || car.getPosition().left + 100 > windowWidth)
        {
            car.reboundSides();
        }

        if (car.getPosition().intersects(player.getPosition()))
        {
            lives--;

            if (lives < 1)
            {
                score = 0;
                lives = 3;
            }

            std::cout<< "Pointer: " << &car << std::endl;
            car = Car(0, 100);
            car.setXPosition(car.getXPosition(windowWidth));
        }


        car.update();
        player.update();

        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());

        window.clear(Color(26, 128, 182, 255));
        window.draw(player.getShape());
        window.draw(car.getShape());
        window.draw(hud);
        window.display();
    }

    return 0;
}