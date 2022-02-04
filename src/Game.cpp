#include "Game.hpp"

// Static init functions
void Game::initWindow()
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    this->mptr_window = new sf::RenderWindow(sf::VideoMode(
        desktopMode.width,
        desktopMode.height,
        desktopMode.bitsPerPixel
    ), m_Title + " " + m_Version, sf::Style::Fullscreen);
    this->mptr_window->setFramerateLimit(120);
    this->mptr_window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
    this->mptr_states.push(new GameState(this->mptr_window));
}

// Constructors
Game::Game()
    : m_Title {"Dense Woods"}, m_Version {"v1.0"}
{
    this->initWindow();
    this->initStates();

    std::clog << "Game object constructed.." << std::endl;
}

// Deconstructors
Game::~Game()
{
    delete this->mptr_window; // Delete window created in initWindow

    // Delete all states
    while (!this->mptr_states.empty())
    {
        delete this->mptr_states.top(); // Delete top state
        this->mptr_states.pop(); // Pop top state
    }

    std::clog << "Game object deconstructed.." << std::endl;
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
    if (!this->mptr_states.empty())
    {
        // Update the top state on the stack
        this->mptr_states.top()->update(this->m_dt);

        // Delete the top state if it requests to quit
        if (this->mptr_states.top()->getQuit())
        {
            this->mptr_states.top()->endStateActions(); // Handle any information about state before it is deleted
            delete this->mptr_states.top(); // Delete top state
            this->mptr_states.pop(); // Remove top state from stack
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
    if (!this->mptr_states.empty())
    {
        // Render the top states if the states stack is not empty
        this->mptr_states.top()->render(this->mptr_window);
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