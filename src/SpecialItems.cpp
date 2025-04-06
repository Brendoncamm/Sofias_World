#include "SpecialItems.h"
#include <iostream>

SpecialItems::SpecialItems()
{
    std::cout << "Special item constructor called" << std::endl;    
    if (!sofiaSootherTexture.loadFromFile("Images/Soother.png"))
    {
        std::cout << "Couldn't load soother texture (Soother.png)" << std::endl;
    }
    itemTextureMap[specialItemType::sofiaPacifier] = sofiaSootherTexture;
}

SpecialItems::~SpecialItems()
{
}

void SpecialItems::createSpecialItem(specialItemType itemType, sf::Vector2f position)
{
    for (const auto& elem : activeSpecialItems)
    {
        // We want to ensure only 1 item type of the special items exist
        if (itemType == elem.itemType)
        {
            std::cout << "Spectial item type has already been added" << std::endl;
            return;
        }
    }

    // Check to make sure texture exists for the item
    auto it = itemTextureMap.find(itemType);
    if (it == itemTextureMap.end())
    {
        std::cerr << "Error, no text for item type: " << (int)itemType << std::endl;
        return;
    }
    
    sf::Sprite itemSprite (it->second);
    itemSprite.setPosition(position);
    itemSprite.setScale({0.5f, 0.5f});

    std::cout << "Adding special item: " << printItemName(itemType) << std::endl;
    activeSpecialItems.emplace_back(std::move(itemSprite), itemType, true);    
}

std::string SpecialItems::printItemName(specialItemType theItem)
{
    switch (theItem)
    {
        case specialItemType::sofiaPacifier:
            return "Sofia's Soother";
        break;

        case specialItemType::sofiaTeddyBear:
            return "Sofias Teddy Bear";
        break;

        default:
            return "";
        break;
    }
}
