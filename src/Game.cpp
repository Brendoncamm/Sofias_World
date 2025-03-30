#include "Game.h"

Game::Game() : sofia(), 
               inputHandler(),
               backgroundTexture("Images/background.png"),
               backgroundSprite(backgroundTexture)
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
        float dt = deltaClock.restart().asSeconds();
        processEvents();
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
    
    // Display the contents of the window
    window.display();
}

void Game::processSofiaMovements(float dt)
{
    // Handle movement input
    sf::Vector2f movement = inputHandler.handleKeyInputs();
    sofia.move(movement, dt);
}