#include "Game.h"
#include <iostream>

Game::Game() : sofia(), 
               inputHandler(),
               backgroundTexture("Images/background.png"),
               backgroundSprite(backgroundTexture),
               theSpecialItem(),
               parentEntity()
{
    // Constructor implementation
    window.create(sf::VideoMode({1920u, 1080u}), "Sofia's World");
    window.setFramerateLimit(144);

}

Game::~Game()
{
    // Destructor implementation
}

void Game::run()
{
    // Main game loop
    while (window.isOpen())
    {
        processEvents();
        float dt = deltaClock.restart().asSeconds();
        // Update game state
        processSofiaMovements(dt);
        render();
    }
}

void Game::processEvents()
{
    // Handle events
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                window.close();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::M)
            {
                sofia.amplifyMovement();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::K)
            {
                theSpecialItem.createSpecialItem(SpecialItems::specialItemType::sofiaPacifier, {500.f, 500.f});
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::L)
            {
                theSpecialItem.removeSpecialItem(SpecialItems::specialItemType::sofiaPacifier);
            }
        }
    }
}

void Game::render()
{
    // Clear the window
    window.clear();
    
    // Draw the background
    window.draw(backgroundSprite);
    
    // Draw Sofia
    window.draw(sofia.getSprite());

    // Draw special items
    if (theSpecialItem.specialItemIsSpawned(SpecialItems::specialItemType::sofiaPacifier))
    {
        auto itemSprite = theSpecialItem.getSpecialItemSprite(SpecialItems::specialItemType::sofiaPacifier);
        if (itemSprite)
        {
            window.draw(*itemSprite);
        }
    }
    // Process object interactions
    processObjectInteractions();

    window.draw(parentEntity.drawAndAnimate());
    // Display the contents of the window
    window.display();
}

void Game::processSofiaMovements(float dt)
{
    // Handle movement input
    sf::Vector2f movement = inputHandler.handleKeyInputs();
    if (movement.x != 0.f || movement.y != 0.f)
    {
        sofia.move(movement, dt);
    }
    else
    {
        sofia.setAnimationToFirstFrame();
    }
    
}

void Game::processObjectInteractions()
{
    if (theSpecialItem.specialItemIsSpawned(SpecialItems::specialItemType::sofiaPacifier))
    {
        sf::FloatRect sofiaBounds = sofia.getSprite().getGlobalBounds();
        sf::FloatRect itemBounds = theSpecialItem.getSpecialItemSprite(SpecialItems::specialItemType::sofiaPacifier)->getGlobalBounds();

        // Check for intersection between Sofia and the special item
        // If the intersection is not empty, it means Sofia is interacting with the item
        if (sofiaBounds.findIntersection(itemBounds).has_value())
        {
            // Handle interaction with the special item
            std::cout << "Sofia picked up the special item!" << std::endl;
            theSpecialItem.removeSpecialItem(SpecialItems::specialItemType::sofiaPacifier);
            sofia.sofiaHasSoother();
        }
    }
}