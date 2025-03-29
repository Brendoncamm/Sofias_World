
#pragma once
#include <SFML/Graphics.hpp>
class theSofia
{
    public:
    theSofia();
    ~theSofia();
    const sf::Sprite getSprite() const;

    private:
    sf::Texture myTexture;
    std::optional<sf::Sprite> mySprite;


};