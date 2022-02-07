#ifndef _PAUSEMENU_HPP_
#define _PAUSEMENU_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

#include "Button.hpp"

class PauseMenu
{
// Variables
private:
    sf::RectangleShape m_background;
    sf::RectangleShape m_container;

    std::map<std::string, Button *> m_buttons;
public:

// Functions
private:
    void initButtons();
public:
    // Constructors
    PauseMenu(sf::RenderWindow &window);

    // Deconstructods
    virtual ~PauseMenu();

    // Functions
    void update();
    void render(sf::RenderTarget &target);
};

#endif