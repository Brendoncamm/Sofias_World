#include "theSofia.h"
#include <iostream>


theSofia::theSofia()
{
    if (!myTexture.loadFromFile("src/Sofia_Happy.PNG"))
    {
        std::cout << "Can't load the file: Sofia_Happy.PNG" << std::endl;
    }
    std::cout << "theSofia constructor called" << std::endl;
    mySprite.emplace(myTexture);
    mySprite->setPosition({500, 300});
    mySprite->setScale({0.05f, 0.05f});

}

theSofia::~theSofia()
{
    std::cout << "theSofia destructor called" << std::endl;
}

const sf::Sprite theSofia::getSprite() const
{
    if (!mySprite)
    {
        std::cerr << "Error: mySprite is not initialized." << std::endl;
        throw std::runtime_error("mySprite is not initialized");
    }
    // Return a copy of the sprite
    return *mySprite;
}

void theSofia::move(sf::Keyboard::Scancode direction, float speed)
{
    // Move the sprite by 1 pixel to the right
    if (!mySprite)
    {
        std::cerr << "Error: mySprite is not initialized." << std::endl;
        return;
    }
    
    float speedOfPixels = 2000.f; // Speed in pixels per second
    sf::Vector2f movement(0.f, 0.f);

    switch (direction)
    {
        case sf::Keyboard::Scancode::W:
            movement.y -= 1.f;
            break;
        case sf::Keyboard::Scancode::S:
            movement.y += 1.f;
            break;
        case sf::Keyboard::Scancode::A:
            movement.x -= 1.f;
            break;
        case sf::Keyboard::Scancode::D:
            movement.x += 1.f;
            break;
        default:
            std::cout << "Error: Invalid direction" << std::endl;
            break;
    }
    if (movement.x !=0.f || movement.y != 0.f)
    {
        // Normalize the movement vector
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        if (length != 0.f)
        {
            movement /= length;
        }
    }
    // Scale the movement vector by the speed and delta time
    mySprite->move(movement * speedOfPixels * speed);
}
