#ifndef COMMONSPRITEUTILITIES_H
#define COMMONSPRITEUTILITIES_H

#include <SFML/Graphics.hpp>
#include "CommonSpriteConstants.h"

namespace CommonSpriteUtilities
{
    inline sf::IntRect getAnimationFrameRect64(int currentFrame)
    {
        int x = CommonSpriteConstants::SHEET_OFFSET.x + (CommonSpriteConstants::FRAME_WIDTH_64 * currentFrame);
        int y = CommonSpriteConstants::SHEET_OFFSET.y;
        return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(CommonSpriteConstants::FRAME_WIDTH_64, CommonSpriteConstants::FRAME_WIDTH_64));
    }

    inline sf::IntRect getAnimationFrameRect32(int currentFrame)
    {
        int x = CommonSpriteConstants::SHEET_OFFSET.x + (CommonSpriteConstants::FRAME_WIDTH_32 * currentFrame);
        int y = CommonSpriteConstants::SHEET_OFFSET.y;
        return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(CommonSpriteConstants::FRAME_WIDTH_32, CommonSpriteConstants::FRAME_WIDTH_32));
    }
}
#endif // COMMONSPRITEUTILITIES_H
