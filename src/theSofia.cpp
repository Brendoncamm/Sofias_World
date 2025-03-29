#include "theSofia.h"
#include <iostream>


theSofia::theSofia()
{
    if (!myTexture.loadFromFile("Sofia_Happy.PNG"))
    {
        std::cout << "Can't load the file: Sofia_Happy.PNG" << std::endl;
    }
    std::cout << "theSofia constructor called" << std::endl;
    mySprite.emplace(myTexture);
    mySprite->setPosition({500, 300});
    mySprite->setScale({0.5f, 0.5f});

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
