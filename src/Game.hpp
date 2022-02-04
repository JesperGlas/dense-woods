#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "MainMenuState.hpp"

class Game
{
// Variables
private:
    const std::string m_Title;
    const std::string m_Version;

    sf::RenderWindow *mptr_window;
    sf::Event m_sfEvent;

    sf::Clock m_dtClock; // Delta clock
    float m_dt; // Delta time

    std::stack<State *> m_states;

    std::map<std::string, sf::Keyboard::Key> supportedKeys;
public:

// Functions
private:
    // Static init functions
    void initWindow();
    void initStates();
    void initKeys();

public:
    // Constructors
    Game();

    // Deconstructors
    virtual ~Game();

    /* Functions */

    // Updates
    void updateDeltaTime();
    void updateSFMLEvents();
    void update();

    // Render
    void render();

    // Core
    void run();
    void endApplication();
};

#endif