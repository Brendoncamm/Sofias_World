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
    SpecialItemInstance itemInstance;
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
    
    itemInstance.itemType = itemType;
    itemInstance.itemSprite.emplace(it->second); // it->second aligns with the texture for the associated item type
    itemInstance.itemSprite->setPosition(position);
    itemInstance.itemSprite->setScale({0.5f, 0.5f});
    itemInstance.isItemSpawned = true;
    std::cout << "Adding special item: " << printItemName(itemType) << std::endl;
    activeSpecialItems.push_back(itemInstance);    
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

