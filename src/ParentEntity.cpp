#include "ParentEntity.h"
#include "CommonSpriteConstants.h"
#include "CommonSpriteUtilities.h"
#include <iostream>

ParentEntity::ParentEntity() : currentFrame((int)CommonSpriteConstants::FRAME_NUMBER::FIRST)
{
    // Load the texture from file
    if (!dadWorkTexture.loadFromFile("Images/Dad_Work.png"))
    {
        std::cout << "Can't load the file: Dad_Work.PNG" << std::endl;
    }
    // Create the sprite and set its texture
    dadWorkSprite.emplace(dadWorkTexture);
    // Set the initial position and scale of the sprite
    dadWorkSprite->setPosition(CommonSpriteConstants::DEFAULT_POSITION);
    dadWorkSprite->setScale(CommonSpriteConstants::DEFAULT_CHARACTER_SCALE*2.f);
}

ParentEntity::~ParentEntity()
{
    std::cout << "ParentEntity destructor called" << std::endl;
}

sf::Sprite ParentEntity::drawAndAnimate()
{
    if (animationClock.getElapsedTime().asSeconds() > CommonSpriteConstants::FRAME_DURATION)
    {
        currentFrame = (currentFrame + 1) % CommonSpriteConstants::TOTAL_FRAMES; // Update the current frame
        animationClock.restart(); // Restart the clock for the next frame
    }

    dadWorkSprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_32>(currentFrame)); // Set the texture rectangle to the current frame
    // Return a copy of the sprite
    return *dadWorkSprite;
}