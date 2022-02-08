#include "GameState.hpp"

/* === Private Functions === */

void GameState::initKeybinds()
{
    this->setKeybind("PAUSE_MENU", this->getSupportedKey("Escape"));
    this->setKeybind("PAUSE_TIME", this->getSupportedKey("Space"));
    this->setKeybind("MOVE_UP", this->getSupportedKey("W"));
    this->setKeybind("MOVE_LEFT", this->getSupportedKey("A"));
    this->setKeybind("MOVE_DOWN", this->getSupportedKey("S"));
    this->setKeybind("MOVE_RIGHT", this->getSupportedKey("D"));
    this->setKeybind("FORCE_EXIT", this->getSupportedKey("E"));
}

void GameState::initTextures()
{
    std:: clog << "Init textures in GameState.." << std::endl;
    this->addTexture("PLAYER", "assets/img/sub_1.png");
}

void GameState::initPlayer()
{
    this->mptr_player = new Player(
        this->getWindow()->getSize().x/2,
        this->getWindow()->getSize().y/2,
        this->m_textures.at("PLAYER"));
}

void GameState::initPauseMenu()
{
    this->m_pauseMenu.addButton("CONTINUE_GAME", "Continue");
    this->m_pauseMenu.addButton("EXIT_STATE", "Quit Game");
}

// Constructors
GameState::GameState(
    sf::RenderWindow *window,
    std::map<std::string, sf::Keyboard::Key> &supportedKeys,
    std::stack<State *> &states
    ) : State(window, supportedKeys, states),
        m_pauseMenu {*this}
{
    std::clog << "==> Constructing GameState object.." << std::endl;

    std::clog << "GameState init functions.." << std::endl;
    this->initKeybinds();
    this->initTextures();
    this->initPlayer();
    this->initPauseMenu();

    // Init background
    this->m_background.setSize(sf::Vector2f(this->getWindow()->getSize()));
    this->m_background.setPosition(sf::Vector2f(0.f, 0.f));
    this->m_background.setFillColor(sf::Color::Blue);

    std::clog << "<== GameState object constructed!" << std::endl;
}

// Deconstructors
GameState::~GameState()
{
    std::clog << "Deconstructing GameState object.." << std::endl;

    delete this->mptr_player;

    std::clog << "GameState object deconstructed!" << std::endl;
}

// Public Functions
void GameState::endStateActions()
{
    std::clog << "Performing endStateActions on GameState.." << std::endl;
}

void GameState::updateInput(const float &dt)
{
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("PAUSE_MENU")) && this->getKeytime())
    {
        if (this->checkIfStatePaused())
            this->setStatePause(false);
        else
            this->setStatePause(true);
    }

    // Temporary to force an exit
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("FORCE_EXIT")))
    {
        this->setStateEnd();
    }
}

void GameState::updatePauseMenu(const float &dt)
{
    if (this->m_pauseMenu.isButtonPressed("CONTINUE_GAME"))
    {
        this->setStatePause(false);
    }
    if (this->m_pauseMenu.isButtonPressed("EXIT_STATE"))
    {
        this->setStateEnd();
    }
}

void GameState::updatePlayerInput(const float &dt)
{
    // Update player input
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_UP")))
    {
        this->mptr_player->move(0.f, -1.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_LEFT")))
    {
        this->mptr_player->move(-1.f, 0.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_DOWN")))
    {
        this->mptr_player->move(0.f, 1.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(this->getKeyBind("MOVE_RIGHT")))
    {
        this->mptr_player->move(1.f, 0.f, dt);
    }
}

void GameState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateKeyTime(dt);

    this->updateInput(dt);

    if (this->checkIfStatePaused())
    {
        this->updatePauseMenu(dt);
        this->m_pauseMenu.update(dt);
    }
    else
    {
        this->updatePlayerInput(dt);
        this->mptr_player->update(dt);
    }
}

void GameState::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->getWindow();
    }

    // Render background
    target->draw(this->m_background);

    this->mptr_player->render(*target);

    if (this->checkIfStatePaused())
    {
        this->m_pauseMenu.render(*target);
    }
}

