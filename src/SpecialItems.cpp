#include "SpecialItems.h"
#include <iostream>

SpecialItems::SpecialItems()
{
    std::cout << "Special item constructor called" << std::endl;   

    if (!sofiaSootherTexture.loadFromFile("Images/Transparent_Soother.png"))
    {
        std::cout << "Couldn't load soother texture (Transparent_Soother.png)" << std::endl;
    }

    itemTextureMap[specialItemType::sofiaPacifier] = sofiaSootherTexture;
}

SpecialItems::~SpecialItems()
{
}

void SpecialItems::createSpecialItem(specialItemType itemType, sf::Vector2f position)
{
    for (auto& elem : activeSpecialItems)
    {
        // If the item has already been added, make sure it's able 
        // to be spawned again
        // This is useful for when the item is removed and then
        // added again
        if (itemType == elem.itemType &&
            !elem.isItemSpawned)
        {
           elem.isItemSpawned = true;
           std::cout << "Spawning special item: " << printItemName(itemType) << std::endl;
        }

        return;
    }

    // Check to make sure texture exists for the item
    auto it = itemTextureMap.find(itemType);
    if (it == itemTextureMap.end())
    {
        std::cerr << "Error, no texture for item type: " << (int)itemType << std::endl;
        return;
    }
    
    sf::Sprite itemSprite (it->second);
    itemSprite.setPosition(position);
    itemSprite.setScale({1.f, 1.f});

    std::cout << "Adding special item: " << printItemName(itemType) << std::endl;
    activeSpecialItems.emplace_back(std::move(itemSprite), itemType, true);    
}

std::optional<sf::Sprite> SpecialItems::getSpecialItemSprite(specialItemType itemType) const
{
    for (const auto& elem : activeSpecialItems)
    {
        if (elem.itemType == itemType && 
            elem.isItemSpawned)
        {
            if (!elem.itemSprite)
            {
                std::cerr << "Error: itemSprite is not initialized." << std::endl;
                return std::nullopt;
            }
            return *elem.itemSprite;
        }
    }
    return std::nullopt;
}

void SpecialItems::removeSpecialItem(specialItemType itemType)
{
    for (auto& elem : activeSpecialItems)
    {
        if (elem.itemType == itemType)
        {
            std::cout << "Removing special item: " << printItemName(itemType) << std::endl;
            elem.isItemSpawned = false;
            return;
        }
    }
}

bool SpecialItems::specialItemIsSpawned(specialItemType itemType)
{
    // Return right away if no special items exist
    // This is a performance optimization
    // to avoid looping through the vector if it is empty
    if (activeSpecialItems.empty())
    {
        return false;
    }

    for (const auto& elem : activeSpecialItems)
    {
        if (elem.itemType == itemType && 
            elem.isItemSpawned)
        {
            return true;
        }
    }

    return false;
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
