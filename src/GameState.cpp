#include "GameState.hpp"

// Constructors
GameState::GameState(sf::RenderWindow *window)
    : State(window)
{
    std::clog << "GameState object constructed.." << std::endl;
}

// Deconstructors
GameState::~GameState()
{
    std::clog << "GameState object deconstructed.." << std::endl;
}

// Functions
void GameState::endStateActions()
{
    std::clog << "Performing endStateActions on GameState.." << std::endl;
}

void GameState::updateKeyBinds(const float &dt)
{
    this->checkForQuit();
}

void GameState::update(const float &dt)
{
    this->updateKeyBinds(dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::clog << "A key is pressed!" << std::endl;
    }
}

void GameState::render(sf::RenderTarget *mptr_target)
{
    
}

