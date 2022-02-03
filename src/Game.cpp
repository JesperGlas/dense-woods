#include "Game.hpp"

// Static init functions
void Game::initWindow()
{
        // Init window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    this->m_window = new sf::RenderWindow(sf::VideoMode(
        desktopMode.width,
        desktopMode.height,
        desktopMode.bitsPerPixel
    ), m_Title + " " + m_Version, sf::Style::Fullscreen);
}

// Constructors
Game::Game()
    : m_Title {"Dense Woods"}, m_Version {"v1.0"}
{
    this->initWindow();
    std::clog << "Game object constructed.." << std::endl;
}

// Deconstructors
Game::~Game()
{
    delete this->m_window; // Delete window created in initWindow
    std::clog << "Game object deconstructed.." << std::endl;
}

// Functions
void Game::updateSFMLEvents()
{
    while (this->m_window->pollEvent(this->m_sfEvent))
    {
        if (this->m_sfEvent.type == sf::Event::Closed || this->m_sfEvent.key.code == sf::Keyboard::Escape)
            this->m_window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->m_window->clear(sf::Color::White);

    // Render items

    this->m_window->display();
}

void Game::run()
{
    while (this->m_window->isOpen())
    {
        this->update();
        this->render();
    }
}