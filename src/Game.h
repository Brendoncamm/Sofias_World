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
    // Event handling
    void processEvents();

    // Process main character movements
    // dt is the delta time in seconds
    // It is used to make the movement speed independent of the frame rate
    void processSofiaMovements(float dt);

    // Game related members
    theSofia sofia;
    MovementInputHandler inputHandler;

    // SFML related members
    sf::RenderWindow window;
    sf::Clock deltaClock;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};