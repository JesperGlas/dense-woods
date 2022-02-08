#ifndef _SETTINGSSTATE_HPP_
#define _SETTINGSSTATE_HPP_

#include "State.hpp"

class SettingsState
    : public State
{
// Variables
private:
    sf::Texture m_backgroundTexture;
    sf::RectangleShape m_background;
    sf::Text m_title;

    std::map<std::string, Button *> m_buttons;
public:

// Functions
private:
    void initVariables();
    void initBackground();
    void initKeybinds();
    void initButtons();
public:
    // Constructor
    SettingsState(
        sf::RenderWindow &widow,
        std::map<std::string, sf::Keyboard::Key> &supportedKeys,
        std::stack<State *> &states
    );

    // Deconstructor
    virtual ~SettingsState();

    // Functions
    void endStateActions();
    void updateInput(const float &dt);
    void updateButtons();
    void update(const float &dt);
    void renderButtons(sf::RenderTarget &target);
    void render(sf::RenderTarget &target);
};

#endif