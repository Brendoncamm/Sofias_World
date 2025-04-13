#include "EntityMovementManager.h"
#include "CommonSpriteConstants.h"
#include "PerlinNoise.hpp"
#include <iostream>

EntityMovementManager::EntityMovementManager()
{
    // Constructor implementation
}
EntityMovementManager::~EntityMovementManager()
{
    // Destructor implementation
}
void EntityMovementManager::moveEntityToMatchSofia(sf::Sprite& entity, sf::Vector2f movement, float speed)
{
    // Move the entity by the given movement vector
    // TODO - This is not implemented to match sofia yet
    entity.move(movement * speed);
}
void EntityMovementManager::moveEntityContinuously(sf::Sprite& entity, sf::Vector2f movement, float speed)
{
    // Move the entity continuously by the given movement vector
    entity.move(movement * speed);
}
void EntityMovementManager::moveEntityRandomly(sf::Sprite& entity, float speed)
{
    // Use Perlin noise to generate random movement
    PerlinNoise perlin;
    float noiseX = perlin.noise(speed, 0,0);
    float noiseY = perlin.noise(speed,100,0);
    
    // map the noise from [0,1] to [-1,1]
    float dirX = noiseX*2.f - 1.f;
    float dirY = noiseY*2.f - 1.f;

    // Velocity vector
    sf::Vector2f velocity(dirX*100, dirY*100); // 100 is the speed in pixels/second
    entity.move(velocity);
}