#include "TextureManager.h"
#include "../common/json.hpp"
#include <fstream>
#include <iostream>

TextureManager::TextureManager()
{
    generateTextureMap();
}

TextureManager::~TextureManager()
{
    // Destructor implementation
}

void TextureManager::generateTextureMap()
{
    // Load the textures from JSON file
    std::ifstream file("src/Textures.JSON");
    if (!file.is_open())
    {
        std::cerr << "Error opening JSON file" << std::endl;
        return;
    }
    nlohmann::json jsonData;
    file >> jsonData;
    file.close();
    std::cout << "JSON data size: " << jsonData.size() << std::endl;
    // Iterate through the JSON data and load textures
    for (const auto& item : jsonData.items())
    {
        const std::string& key = item.key();
        const std::string& filePath = item.value();
        std::cout << "Loading texture: " << key << " from " << filePath << std::endl;
        // Create a new texture and load it from the file
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(filePath))
        {
            std::cerr << "Error loading texture: " << filePath << std::endl;
            continue;
        }
        
        // Store the texture in the map
        textureMap[key] = texture;
    }
    // Print the loaded textures
    std::cout << "Added textures to map:" << std::endl;
    for (const auto& pair : textureMap)
    {
        std::cout << "Key: " << pair.first << ", Texture: " << pair.second.get() << std::endl;
    }
    // Print the number of loaded textures
    std::cout << "Number of loaded textures: " << textureMap.size() << std::endl;
}

std::shared_ptr<sf::Texture> TextureManager::getTexture(const std::string & key)
{
    auto it = textureMap.find(key);
    if (it != textureMap.end())
    {
        return it->second;
    }
    else
    {
        std::cerr << "Texture not found: " << key << std::endl;
        return nullptr;
    }
}

void TextureManager::didEntityTextureLoad(std::shared_ptr<sf::Texture> texture, const char* textureName)
{
    if (!texture)
    {
        std::cerr << "Error: Texture not loaded: " << textureName << std::endl;
        return;
    }
    else
    {
        std::cout << "Texture loaded successfully: " << textureName << std::endl;
    }
}