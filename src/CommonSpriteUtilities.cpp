
/*
#include "CommonSpriteUtilities.h"
#include "CommonSpriteConstants.h"

namespace CommonSpriteUtilities
{
    sf::IntRect getAnimationFrameRect64(int currentFrame)
    {
        int x = CommonSpriteConstants::SHEET_OFFSET.x + (CommonSpriteConstants::FRAME_WIDTH_64 * currentFrame);
        int y = CommonSpriteConstants::SHEET_OFFSET.y;
        return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(CommonSpriteConstants::FRAME_WIDTH_64, CommonSpriteConstants::FRAME_WIDTH_64));
    }

    sf::IntRect getAnimationFrameRect32(int currentFrame)
    {
        int x = CommonSpriteConstants::SHEET_OFFSET.x + (CommonSpriteConstants::FRAME_WIDTH_32 * currentFrame);
        int y = CommonSpriteConstants::SHEET_OFFSET.y;
        return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(CommonSpriteConstants::FRAME_WIDTH_32, CommonSpriteConstants::FRAME_WIDTH_32));
    }
}
*/