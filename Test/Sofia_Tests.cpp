#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/theSofia.h"

TEST_CASE("Sofia Moves Correctly", "[movement]")
{
    theSofia sofia;

    sf::Vector2f initialPosition = sofia.getSprite().getPosition();
    sf::Vector2f moveLeft (-10.f, 0.f);
    sofia.move(moveLeft, 10.0);
    sf::Vector2f newPosition = sofia.getSprite().getPosition();
    
    REQUIRE(newPosition.x < initialPosition.x);
    REQUIRE(newPosition.y == Approx(initialPosition.y));
}

