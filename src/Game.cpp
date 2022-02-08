#include "Game.hpp"

void Game::initWindow()
{
    bool fullscreen{true}; // Unused for now
    unsigned framerate_limit{120};
    bool vertical_sync{false};
    unsigned antialiasing_level{4}; // Lower in case of high load lol

    this->m_windowSettings.antialiasingLevel = antialiasing_level;

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    this->m_videoModes = sf::VideoMode::getFullscreenModes();
    this->mptr_window = new sf::RenderWindow(
        sf::VideoMode(desktopMode),
        m_Title + " " + m_Version,
        sf::Style::Fullscreen,
        this->m_windowSettings);
    this->mptr_window->setFramerateLimit(framerate_limit);
    this->mptr_window->setVerticalSyncEnabled(vertical_sync);
}

void Game::initKeys()
{
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["Space"] = sf::Keyboard::Key::Space;
    this->supportedKeys["Q"] = sf::Keyboard::Key::Q;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["E"] = sf::Keyboard::Key::E;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
}

void Game::initStates()
{
    // Push MainMenuState
    this->m_states.push(
        new MainMenuState(
            this->mptr_window,
            this->supportedKeys,
            &this->m_states
        )
    );
}

// Constructors
Game::Game()
    : m_Title{"Dense Woods"}, m_Version{"v1.0"}, mptr_window{nullptr}, m_dt{0}
{
    std::clog << "Constructing Game object.." << std::endl;

    this->initWindow();
    this->initKeys();
    this->initStates();

    std::clog << "Game object constructed!" << std::endl;
}

// Deconstructors
Game::~Game()
{
    std::clog << "Deconstructing Game object.." << std::endl;

    delete this->mptr_window; // Delete window created in initWindow

    // Delete all states
    while (!this->m_states.empty())
    {
        delete this->m_states.top(); // Delete top state
        this->m_states.pop();        // Pop top state
    }

    std::clog << "Game object deconstructed!" << std::endl;
}

// Functions
void Game::updateDeltaTime()
{
    /* Updates the m_dt variable with the time it takes to update and render one frame */
    this->m_dt = this->m_dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->mptr_window->pollEvent(this->m_sfEvent))
    {
        
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    // Update top state if state stack is not empty
    if (!this->m_states.empty())
    {
        // Update the top state on the stack
        this->m_states.top()->update(this->m_dt);

        // Delete the top state if it requests to quit
        if (this->m_states.top()->checkIfStateEnd())
        {
            this->m_states.top()->endStateActions(); // Handle any information about state before it is deleted
            delete this->m_states.top();             // Delete top state
            this->m_states.pop();                    // Remove top state from stack
        }
    }
    // Application end
    else
    {
        this->endApplication();
        this->mptr_window->close();
    }
}

void Game::render()
{
    this->mptr_window->clear(sf::Color::White);

    // Render items
    if (!this->m_states.empty())
    {
        // Render the top states if the states stack is not empty
        this->m_states.top()->render(this->mptr_window);
    }

    this->mptr_window->display();
}

void Game::run()
{
    while (this->mptr_window->isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}

void Game::endApplication()
{
    std::clog << "Performing actions before closing the Game.." << std::endl;
}