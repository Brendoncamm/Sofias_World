#include "MovementInputHandler.h"
#include <cmath>
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
    
    // Normalize the movement vector to ensure consistent speed
    // If this isn't done when 2 keys are pressed at the same time, the speed will be faster
    // than when only 1 key is pressed
    if (movement.x != 0.f || movement.y != 0.f)
    {
        float length = sqrt(movement.x * movement.x + movement.y * movement.y);
        if (length != 0.f)
        {
            movement /= length;
        }
    }
    
    return movement;
}