#include "theSofia.h"
#include "MovementInputHandler.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Sofias World");
    window.setFramerateLimit(144);
    sf::Clock deltaClock;
    theSofia sofia = theSofia();
    MovementInputHandler inputHandler = MovementInputHandler();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Images/background.png"))
    {
        std::cerr << "Error loading background texture" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

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
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::M)
                {
                    sofia.amplifyMovement();
                }
            }
                        
        }
        // Handle movement input
        sf::Vector2f movement = inputHandler.handleKeyInputs();
        sofia.move(movement, dt);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(sofia.getSprite());
        window.display();
    }
}
