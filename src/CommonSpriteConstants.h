#ifndef COMMONSPRITECONSTANTS_H
#define COMMONSPRITECONSTANTS_H
#include <SFML/Graphics.hpp>

namespace CommonSpriteConstants
{
    inline constexpr int SPRITE_WIDTH_32  = 32;
    inline constexpr int SPRITE_HEIGHT_32 = 32;
    inline constexpr int SPRITE_WIDTH_64  = 64;
    inline constexpr int SPRITE_HEIGHT_64 = 64;
    inline constexpr int SPRITE_FRAME_SIZE_32 = 32;
    inline constexpr int SPRITE_FRAME_SIZE_64 = 64;

    inline constexpr sf::Vector2i SPRITE_SHEET_OFFSET = {0, 0};
    inline constexpr sf::Vector2f REFLECT_LEFT        = {-2.f, 2.f};
    inline constexpr sf::Vector2f REFLECT_RIGHT       = {2.f, 2.f};
    inline constexpr sf::Vector2i SHEET_OFFSET        = {0, 0};
    inline constexpr sf::Vector2f DEFAULT_POSITION    = {500, 300};
    inline constexpr sf::Vector2f DEFAULT_GROUND_ITEM_SCALE = {2.f, 2.f};

    inline constexpr float FRAME_DURATION = 1.0f;
    inline constexpr int TOTAL_FRAMES = 2;
    
    enum class FRAME_NUMBER
    {
        FIRST = 0,
        SECOND = 1,
        THIRD = 2,
        FOURTH = 3,
    };
};
#endif // COMMONSPRITECONSTANTS_H
