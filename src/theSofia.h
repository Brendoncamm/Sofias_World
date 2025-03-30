
#pragma once
#include <SFML/Graphics.hpp>
class theSofia
{
    public:
    theSofia();
    ~theSofia();
    const sf::Sprite getSprite() const;
    void move(sf::Vector2f movement, float speed);

    private:
    sf::Texture myTexture;
    std::optional<sf::Sprite> mySprite;


};