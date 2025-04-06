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

    // Struct corresponding to special items.
    struct SpecialItemInstance
    {
        std::optional<sf::Sprite>  itemSprite;
        specialItemType itemType;
        bool        isItemSpawned = false;
    };

    void createSpecialItem(specialItemType itemType, sf::Vector2f position);
    sf::Sprite drawSpecialItem(specialItemType);

    private:
    std::unordered_map<specialItemType, sf::Texture> itemTextureMap;
    std::vector<SpecialItemInstance> activeSpecialItems;
    sf::Texture sofiaSootherTexture;
    std::optional<sf::Sprite> sofiaSoother;
    std::string printItemName(specialItemType itemType);
      

};