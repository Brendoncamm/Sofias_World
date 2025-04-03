#include "theSofia.h"
#include <iostream>


// Sofia Sprite Sheet Constants

int frameWidth = 288;
int frameHeight = 320;
int totalFrames = 4;
int currentFrame = 0;
float frameDuration = 1.0f; // Duration of each frame in seconds

sf::Vector2i sheetOffset = {0,0};
theSofia::theSofia() : amplifiedMovement(false)
{
    if (!myTexture.loadFromFile("Images/Sofia_Sprite_Sheet.png"))
    {
        std::cout << "Can't load the file: Sofia_Happy.PNG" << std::endl;
    }
    std::cout << "theSofia constructor called" << std::endl;
    
    mySprite.emplace(myTexture);// Define the rectangle for the sprite
    mySprite->setTextureRect(getFrameRect(0));// Set the texture rectangle to the first frame
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

void theSofia::move(sf::Vector2f movement, float speed)
{
    // Move the sprite by 1 pixel to the right
    if (!mySprite)
    {
        std::cerr << "Error: mySprite is not initialized." << std::endl;
        return;
    }
    
    currentFrame = (currentFrame + 1) % totalFrames; // Update the current frame
    mySprite->setTextureRect(getFrameRect(currentFrame)); // Set the texture rectangle to the current frame

    float speedOfPixels = 20.f; // Speed in pixels per second

    if (amplifiedMovement)
    {
        speedOfPixels *= 20.f; // Double the speed if amplified
    }

    mySprite->move(movement * speedOfPixels * speed);

    if (movement.x != 0.f || 
        movement.y != 0.f && 
        animationClock.getElapsedTime().asSeconds() > frameDuration)
    {
        currentFrame = (currentFrame + 1) % totalFrames; // Update the current frame
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
    int x = sheetOffset.x + (frameWidth * frameIndex);
    int y = sheetOffset.y;
    return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(frameWidth, frameHeight));
}

void theSofia::setAnimationToFirstFrame()
{
    currentFrame = 0;
    mySprite->setTextureRect(getFrameRect(currentFrame));
}
