#include "theSofia.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Sofias World", sf::Style::Titlebar, sf::State::Windowed);
    window.setFramerateLimit(144);

    theSofia sofia = theSofia();

    // Game loop
    while (window.isOpen())
    {
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
                if (keyPressed->scancode == sf::Keyboard::Scancode::Delete)
                {
                    window.close();
                }
            }
            else if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
            {
                std::cout << "The mouse wheel has been scrolled!" << std::endl;
                std::cout << "Wheel movement: " << mouseWheelScrolled->delta << std::endl;
            }
        }

        window.clear();
        window.display();
    }
}
