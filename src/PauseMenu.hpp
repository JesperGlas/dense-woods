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
    sf::Font &mref_font;
    sf::Text m_menuTitle;
    sf::RectangleShape m_background;
    sf::RectangleShape m_container;

    std::map<std::string, Button *> m_buttons;
public:

// Functions
private:
    void initButtons();
public:
    // Constructors
    PauseMenu(sf::RenderWindow &window, sf::Font &font);

    // Deconstructods
    virtual ~PauseMenu();

    // Functions
    void update(const sf::Vector2f &mousePosition);
    void render(sf::RenderTarget &target);
};

#endif