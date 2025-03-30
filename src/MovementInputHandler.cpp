#include "MovementInputHandler.h"

MovementInputHandler::MovementInputHandler()
{
    // Constructor implementation
}
MovementInputHandler::~MovementInputHandler()
{
    // Destructor implementation
}   

sf::Vector2f MovementInputHandler::handleKeyInputs()
{
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
        movement.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
        movement.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
    {
        movement.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
    {
        movement.x += 1.f;
    }
    if (movement.x != 0.f || movement.y != 0.f)
    {
        // Normalize the movement vector
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        if (length != 0.f)
        {
            movement /= length;
        }
    }

    return movement;
}