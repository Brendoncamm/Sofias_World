#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "EntityMovementManager.h"

class ParentEntity
{
    public:
    ParentEntity(TextureManager& textureMgr);
    ~ParentEntity();
    sf::Sprite drawAndAnimate();
    void moveDadWorkSprite(float speed);
    void moveDadEntity(float speed);

    private:
    TextureManager textureManager;
    EntityMovementManager entityMovement;
    std::shared_ptr<sf::Texture> dadWorkTexture;
    std::optional<sf::Sprite> dadWorkSprite;
    int currentFrame;
    sf::Clock animationClock;
};