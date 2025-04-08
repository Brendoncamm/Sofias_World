#include <SFML/Graphics.hpp>

class ParentEntity
{
    public:
    ParentEntity();
    ~ParentEntity();
    sf::Sprite drawAndAnimate();

    private:
    sf::Texture dadWorkTexture;
    std::optional<sf::Sprite> dadWorkSprite;
};