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
    this->m_window.create(
        sf::VideoMode(desktopMode),
        this->m_title + " " + this->m_version,
        sf::Style::Fullscreen,
        this->m_windowSettings);
    this->m_window.setFramerateLimit(framerate_limit);
    this->m_window.setVerticalSyncEnabled(vertical_sync);

    std::clog << "=#=> m_window is " << m_window.isOpen() << std::endl;
}

void Game::initKeys()
{
    this->m_supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->m_supportedKeys["Space"] = sf::Keyboard::Key::Space;
    this->m_supportedKeys["Q"] = sf::Keyboard::Key::Q;
    this->m_supportedKeys["W"] = sf::Keyboard::Key::W;
    this->m_supportedKeys["E"] = sf::Keyboard::Key::E;
    this->m_supportedKeys["A"] = sf::Keyboard::Key::A;
    this->m_supportedKeys["S"] = sf::Keyboard::Key::S;
    this->m_supportedKeys["D"] = sf::Keyboard::Key::D;
}

void Game::initStates()
{
    // Push MainMenuState
    this->m_states.push(
        new MainMenuState(
            this->m_window,
            this->m_supportedKeys,
            this->m_states
        )
    );
}

// Constructors
Game::Game()
    :   m_title{"Dense Woods"},
        m_version{"v1.0"},
        m_dt{0}
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
    while (this->m_window.pollEvent(this->m_sfEvent))
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
        this->m_window.close();
    }
}

void Game::render()
{
    this->m_window.clear(sf::Color::White);

    // Render items
    if (!this->m_states.empty())
    {
        // Render the top states if the states stack is not empty
        this->m_states.top()->render(this->m_window);
    }

    this->m_window.display();
}

void Game::endApplication()
{
    std::clog << "Performing actions before closing the Game.." << std::endl;
}

void Game::run()
{
    while (this->m_window.isOpen())
    {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}