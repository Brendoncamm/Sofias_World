#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class ParentEntity
{
    public:
    ParentEntity(TextureManager& textureMgr);
    ~ParentEntity();
    sf::Sprite drawAndAnimate();

    private:
    TextureManager textureManager;
    std::shared_ptr<sf::Texture> dadWorkTexture;
    std::optional<sf::Sprite> dadWorkSprite;
    int currentFrame;
    sf::Clock animationClock;
};