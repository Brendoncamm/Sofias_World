#include <SFML/Graphics.hpp>

namespace CommonSpriteConstants
{
    int FRAME_WIDTH_32_BIT  = 32;
    int FRAME_HEIGHT_32_BIT = 32;
    int FRAME_WIDTH_64_BIT  = 64;
    int FRAME_HEIGHT_64_BIT = 64;

    sf::Vector2i SPRITE_SHEET_OFFSET = {0, 0};
    sf::Vector2f REFLECT_LEFT        = {-5.f, 5.f};
    sf::Vector2f REFLECT_RIGHT       = {5.f, 5.f};
    sf::Vector2i SHEET_OFFSET        = {0, 0};
    float FRAME_DURATION = 1.0f; // Duration of each frame in seconds
    int TOTAL_FRAMES = 2;
};