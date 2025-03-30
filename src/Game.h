#include "theSofia.h"
#include "MovementInputHandler.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();
    void render();
private:
    sf::RenderWindow window;
    sf::Clock deltaClock;
    void processEvents();
    void processSofiaMovements(float dt);
    theSofia sofia;
    MovementInputHandler inputHandler;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};