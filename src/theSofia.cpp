#include "theSofia.h"
#include <iostream>


theSofia::theSofia() : amplifiedMovement(false)
{
    if (!myTexture.loadFromFile("Images/Crawling_Sofia.PNG"))
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

void theSofia::move(sf::Vector2f movement, float speed)
{
    // Move the sprite by 1 pixel to the right
    if (!mySprite)
    {
        std::cerr << "Error: mySprite is not initialized." << std::endl;
        return;
    }
    
    float speedOfPixels = 20.f; // Speed in pixels per second

    if (amplifiedMovement)
    {
        speedOfPixels *= 20.f; // Double the speed if amplified
    }
    mySprite->move(movement * speedOfPixels * speed);
}

void theSofia::amplifyMovement()
{
    std::cout << "Amplifying movement" << std::endl;
    if (!amplifiedMovement)
    {
        amplifiedMovement = true;
        std::cout << "Amplified movement" << std::endl;
    }
    else
    {
        amplifiedMovement = false;
        std::cout << "Normal movement" << std::endl;
    }
    
}