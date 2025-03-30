
#pragma once
#include <SFML/Graphics.hpp>
class theSofia
{
    public:
    theSofia();
    ~theSofia();
    const sf::Sprite getSprite() const;
    void move(sf::Vector2f movement, float speed);
    void amplifyMovement();

    private:
    sf::Texture myTexture;
    std::optional<sf::Sprite> mySprite;
    bool amplifiedMovement;


};