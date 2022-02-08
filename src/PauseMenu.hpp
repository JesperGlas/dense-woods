#ifndef _PAUSEMENU_HPP_
#define _PAUSEMENU_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

#include "State.hpp"

class PauseMenu
{
// Variables
private:
    State &m_state;
    sf::Text m_menuTitle;
    sf::RectangleShape m_background;
    sf::RectangleShape m_container;

    std::map<std::string, gui::Button *> m_buttons;
public:

// Functions
private:
public:
    // Constructors
    PauseMenu(State &state);

    // Deconstructods
    virtual ~PauseMenu();

    // Getters
    const bool isButtonPressed(const std::string key);

    // Functions
    void addButton(const std::string key, std::string text);
    void updateButtons();
    void update(const float &dt);
    void render(sf::RenderTarget &target);
};

#endif