
#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "TextureKeys.h"

class theSofia
{
    public:
    theSofia(TextureManager& textureMgr);
    ~theSofia();
    const sf::Sprite getSprite() const;
    void move(sf::Vector2f movement, float speed);
    void amplifyMovement();
    void setAnimationToFirstFrame();
    void sofiaHasSoother();

    private:
    std::shared_ptr<sf::Texture> sofiaTexture;
    std::shared_ptr<sf::Texture> mySootherTexture;
    std::optional<sf::Sprite> mySprite;
    bool amplifiedMovement;
    sf::Clock animationClock;
    int currentFrame;
    TextureManager& textureManager;

};