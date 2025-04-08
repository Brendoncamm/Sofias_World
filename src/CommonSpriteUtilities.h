#ifndef COMMONSPRITEUTILITIES_H
#define COMMONSPRITEUTILITIES_H

#include <SFML/Graphics.hpp>


namespace CommonSpriteUtilities
{

    template<int PixelPerUnit>
    sf::IntRect getSpriteFrameRect(int currentFrame)
    {
        int x = CommonSpriteConstants::SHEET_OFFSET.x + (PixelPerUnit * currentFrame);
        int y = CommonSpriteConstants::SHEET_OFFSET.y;
        return sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(PixelPerUnit, PixelPerUnit));
    }
}
#endif // COMMONSPRITEUTILITIES_H
