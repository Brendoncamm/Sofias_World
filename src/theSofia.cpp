#include "theSofia.h"
#include "SpecialItems.h"
#include "CommonSpriteConstants.h"
#include "CommonSpriteUtilities.h"
#include "TextureKeys.h"
#include "TextureManager.h"
#include <iostream>


// Sofia Sprite Sheet Constants

theSofia::theSofia(TextureManager& TextureMgr) : amplifiedMovement(false),
                       currentFrame(),
                       textureManager(TextureMgr)
{   
    sofiaTexture = textureManager.getTexture(TextureKeys::Sofia_Crawling_2Frame);
    mySootherTexture = textureManager.getTexture(TextureKeys::Sofia_Soother_2Frame);
    
    mySprite.emplace(*sofiaTexture);// Define the rectangle for the sprite
    mySprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_64>(currentFrame));// Set the texture rectangle to the first frame
    mySprite->setPosition(CommonSpriteConstants::DEFAULT_POSITION);
    mySprite->setScale(CommonSpriteConstants::REFLECT_RIGHT);
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
    
    currentFrame = (currentFrame + 1) % CommonSpriteConstants::TOTAL_FRAMES; // Update the current frame
    mySprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_64>(currentFrame)); // Set the texture rectangle to the current frame

    float speedOfPixels = 20.f; // Speed in pixels per second

    if (amplifiedMovement)
    {
        speedOfPixels *= 20.f; // Double the speed if amplified
    }

    mySprite->move(movement * speedOfPixels * speed);

    // Set the rotation of sofia depending on 
    // which direction she's moving.
    if (movement.x < 0.f)
    {
        mySprite->setScale(CommonSpriteConstants::REFLECT_LEFT);
    }
    else if (movement.y == 0)
    {
        mySprite->setScale(CommonSpriteConstants::REFLECT_RIGHT); // Reset rotation to face right
    }

    if ((movement.x != 0.f || 
         movement.y != 0.f) && 
        animationClock.getElapsedTime().asSeconds() > CommonSpriteConstants::FRAME_DURATION)
    {
        currentFrame = (currentFrame + 1) % CommonSpriteConstants::TOTAL_FRAMES; // Update the current frame
        mySprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_64>(currentFrame)); // Set the texture rectangle to the current frame
        animationClock.restart(); // Restart the clock for the next frame
    }
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

void theSofia::setAnimationToFirstFrame()
{
    mySprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_64>((int)CommonSpriteConstants::FRAME_NUMBER::FIRST)); // Set the texture rectangle to the first frame
}

void theSofia::sofiaHasSoother()
{   
    mySprite->setTexture(*mySootherTexture, true);
    mySprite->setTextureRect(CommonSpriteUtilities::getSpriteFrameRect<CommonSpriteConstants::SPRITE_FRAME_SIZE_64>((int)CommonSpriteConstants::FRAME_NUMBER::FIRST)); // Set the texture rectangle to the first frame>);
    mySprite->setScale({0.5f, 0.5f});
}

