#pragma once
#include <SFML/Graphics.hpp>

// This class is used to management the movement of 
// non-main player entities
class EntityMovementManager
{
    public: 
    EntityMovementManager();
    ~EntityMovementManager();

    // Move the entity by the given movement vector
    // This function is used if you only want to move the entity 
    // Once - for example, if you want to entity to match the 
    // player's position
    // This function is used for one-time movements
    void moveEntity(sf::Sprite& entity, sf::Vector2f movement = {0,0}, float speed = 0.f);
    
    // Move entity by a given movement vector continuously in very defined ways 
    void moveEntityContinuously(sf::Sprite& entity, sf::Vector2f movement = {0,0}, float speed = 0.f);

    // Move entity randomly - this will use perlin noise
    // to move the entity in a random direction
    sf::Vector2f moveEntityRandomly(float dt);

    private:

};