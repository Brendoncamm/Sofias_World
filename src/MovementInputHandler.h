#include <SFML/Graphics.hpp>

class MovementInputHandler
{
public:
    MovementInputHandler();
    ~MovementInputHandler();

    sf::Vector2f handleKeyInputs();

};