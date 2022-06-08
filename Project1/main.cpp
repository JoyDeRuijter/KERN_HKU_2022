#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Joy de Ruijter");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    //shape.setPosition(400.f, 400.f);
    shape.move(5.f, 5.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}