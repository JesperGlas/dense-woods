#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Game
{
// Variables
private:
    const std::string m_Title;
    const std::string m_Version;

    sf::RenderWindow *m_window;
    sf::Event m_sfEvent;
public:

// Functions
private:
    // Static init functions
    void initWindow();

public:
    // Constructors
    Game();

    // Deconstructors
    virtual ~Game();

    // Functions
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};

#endif