#include "theSofia.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Sofias World");
    window.setFramerateLimit(144);
    sf::Clock deltaClock;
    theSofia sofia = theSofia();

    // Game loop
    while (window.isOpen())
    {   
        float dt = deltaClock.restart().asSeconds();
        // Look for events happening in the window
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                std::cout << "There was a keypressed!" <<std::endl;
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
            {
                sofia.move(sf::Keyboard::Scancode::W, dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
            {
                sofia.move(sf::Keyboard::Scancode::S, dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
            {
                sofia.move(sf::Keyboard::Scancode::A, dt);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
            {
                sofia.move(sf::Keyboard::Scancode::D, dt);
            }
        }

        window.clear();
        window.draw(sofia.getSprite());
        window.display();
    }
}
