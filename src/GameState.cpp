#include "GameState.hpp"

// Constructors
GameState::GameState(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
{
    this->initKeybinds();

    // Init background

    std::clog << "GameState object constructed.." << std::endl;
}

// Deconstructors
GameState::~GameState()
{
    std::clog << "GameState object deconstructed.." << std::endl;
}

// Private Functions
void GameState::initFonts()
{
    
}

void GameState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("Escape"));
    this->setKeybind("MOVE_UP", this->getSupportedKey("W"));
    this->setKeybind("MOVE_LEFT", this->getSupportedKey("A"));
    this->setKeybind("MOVE_DOWN", this->getSupportedKey("S"));
    this->setKeybind("MOVE_RIGHT", this->getSupportedKey("D"));
}

// Public Functions
void GameState::endStateActions()
{
    std::clog << "Performing endStateActions on GameState.." << std::endl;
}

void GameState::updateInput(const float &dt)
{
    this->checkForQuit();

    // Update player input
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_UP")))
    {
        this->m_player.move(dt, 0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_LEFT")))
    {
        this->m_player.move(dt, -1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_DOWN")))
    {
        this->m_player.move(dt, 0.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_RIGHT")))
    {
        this->m_player.move(dt, 1.f, 0.f);
    }
}

void GameState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->m_player.update(dt);
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->getWindow();
    }
    this->m_player.render(target);
}

