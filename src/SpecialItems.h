#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>
class SpecialItems
{   
    public:
    SpecialItems();
    ~SpecialItems();

    enum class specialItemType
    {
        sofiaPacifier = 0,
        sofiaTeddyBear = 1
    };

    void createSpecialItem(specialItemType itemType, sf::Vector2f position);
    std::optional<sf::Sprite> getSpecialItemSprite(specialItemType itemType) const;
    bool specialItemIsSpawned(specialItemType itemType);
    void removeSpecialItem(specialItemType itemType);
    private:
    
    // Struct corresponding to special items.
    struct SpecialItemInstance
    {
        std::optional<sf::Sprite>  itemSprite;
        SpecialItems::specialItemType itemType;
        bool        isItemSpawned;
    
        // Struct constructor
        SpecialItemInstance(sf::Sprite&& mySprite,
                            SpecialItems::specialItemType theItem, 
                            bool spawnedState = false) : itemType(theItem),
                                                         isItemSpawned(spawnedState)
                                                       {
                                                         itemSprite.emplace(std::move(mySprite));
                                                       }
    };
    
    std::unordered_map<specialItemType, sf::Texture> itemTextureMap;
    std::vector<SpecialItemInstance> activeSpecialItems;
    sf::Texture sofiaSootherTexture;
    std::optional<sf::Sprite> sofiaSoother;
    std::string printItemName(specialItemType itemType);
    sf::Clock animationClock;
      

};