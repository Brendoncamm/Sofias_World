#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

/**
 * @brief TextureManager is responsible for loading and managing textures.
 * Clients that want to use textures must setup their constructor for 
 * dependancy injection (i.e. myClass(TextureManager& textureMgr)).
 * This allows for easy testing and decoupling of the texture loading
 * process from the rest of the game logic.
 * 
 * Note that this class must be instantiated before any
 * sprites or game objects that rely on textures.
 * 
 * In headers make sure the TextureManager object is declared
 * before the shared_ptr<sf::Texture> objects.
 */
class TextureManager
{
    public:
    TextureManager();
    ~TextureManager();

    // These textures will be available to all game items
    // The choice to use shared_ptr was due to the fact that
    // textures could be used by multiple game items.
    // This way, the texture is only loaded once and shared
    // among all game items that need it.
    // Some textures, like Sofia's main character model, aren't 
    // intended to be shared, but this could change in the future.
    // (Refelctions, shadows, etc.)
    std::shared_ptr<sf::Texture> getTexture(const std::string & key);
    
    void didEntityTextureLoad(std::shared_ptr<sf::Texture> texture, const char* textureName);

    private:
    // Load the textures from JSON file
    void generateTextureMap();
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textureMap;
};