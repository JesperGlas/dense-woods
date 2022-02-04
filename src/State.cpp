#include "State.hpp"

// Constructors
State::State(sf::RenderWindow *window)
    : mptr_window {window}, m_requestQuit {false}
{
    // this->mptr_window = mptr_window;
    std::clog << "State object constructed.." << std::endl;
}

// Deconstructors
State::~State()
{
    std::clog << "State object deconstructed.." << std::endl;
}

// Functions
const bool & State::getQuit() const
{
    return this->m_requestQuit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->m_requestQuit = true;
    }
}