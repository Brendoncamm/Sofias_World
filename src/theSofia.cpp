#include "theSofia.h"
#include "SpecialItems.h"
#include "CommonSpriteConstants.h"
#include <iostream>


// Sofia Sprite Sheet Constants

theSofia::theSofia() : amplifiedMovement(false),
                       currentFrame()
{
    if (!myTexture.loadFromFile("Images/Sofia_Crawling_2Frame.png"))
    {
        std::cout << "Can't load the file: Sofia_Happy.PNG" << std::endl;
    }
    if (!mySootherTexture.loadFromFile("Images/Sofia_Soother_Added.png"))
    {
        std::cout << "Can't load the file: Sofia_Soother_Added.PNG" << std::endl;
    }
    std::cout << "theSofia constructor called" << std::endl;
    
    mySprite.emplace(myTexture);// Define the rectangle for the sprite
    mySprite->setTextureRect(getFrameRect(0));// Set the texture rectangle to the first frame
    mySprite->setPosition({500, 300});
    mySprite->setScale({5.f, 5.f});

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
    mySprite->setTextureRect(getFrameRect(currentFrame)); // Set the texture rectangle to the current frame

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
    std::cout << "Movement x: " << movement.x << std::endl;
    std::cout << "Movement y: " << movement.y << std::endl;
    if (movement.x != 0.f || 
        movement.y != 0.f && 
        animationClock.getElapsedTime().asSeconds() > CommonSpriteConstants::FRAME_DURATION)
    {
        currentFrame = (currentFrame + 1) % CommonSpriteConstants::TOTAL_FRAMES; // Update the current frame
        std::cout << "Current frame: " << currentFrame << std::endl;
        mySprite->setTextureRect(getFrameRect(currentFrame)); // Set the texture rectangle to the current frame
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

sf::IntRect theSofia::getFrameRect(int frameIndex) const
{
    int x = CommonSpriteConstants::SHEET_OFFSET.x + (CommonSpriteConstants::FRAME_WIDTH_64_BIT * frameIndex);
    int y = CommonSpriteConstants::SHEET_OFFSET.y;
    return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(CommonSpriteConstants::FRAME_WIDTH_64_BIT, CommonSpriteConstants::FRAME_WIDTH_64_BIT));
}

void theSofia::setAnimationToFirstFrame()
{
    currentFrame = 0;
    mySprite->setTextureRect(getFrameRect(currentFrame));
}

void theSofia::sofiaHasSoother()
{   
    mySprite->setTexture(mySootherTexture, true);
    mySprite->setTextureRect(getFrameRect(0));
    mySprite->setScale({0.5f, 0.5f});
}

