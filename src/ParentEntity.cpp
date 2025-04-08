#include "ParentEntity.h"
#include <iostream>


int col = 0;
int row = 0;
int spriteSize = 32;
int parentcurrentFrame = 0;
sf::Clock animationClock;
float parentframeDuration = 0.1f; // Duration of each frame in seconds
ParentEntity::ParentEntity()
{
    if (!dadWorkTexture.loadFromFile("Images/Dad_Work.png"))
    {
        std::cout << "Can't load the file: Dad_Work.PNG" << std::endl;
    }
    dadWorkSprite.emplace(dadWorkTexture);// Define the rectangle for the sprite
    dadWorkSprite->setPosition({500, 300});
    dadWorkSprite->setScale({5.f, 5.f});
}

ParentEntity::~ParentEntity()
{
    std::cout << "ParentEntity destructor called" << std::endl;
}

sf::Sprite ParentEntity::drawAndAnimate()
{
    if (animationClock.getElapsedTime().asSeconds() > parentframeDuration)
    {
        parentcurrentFrame = (parentcurrentFrame + 1) % 2; // Update the current frame
        animationClock.restart(); // Restart the clock for the next frame
    }

    dadWorkSprite->setTextureRect(sf::IntRect({parentcurrentFrame*spriteSize, 0}, {spriteSize, spriteSize}));
    // Return a copy of the sprite
    return *dadWorkSprite;
}