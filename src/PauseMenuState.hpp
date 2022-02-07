#ifndef _PAUSEMENUSTATE_HPP_
#define _PAUSEMENUSTATE_HPP_

#include "GameState.hpp"

class PauseMenuState
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
    PauseMenuState(sf::RenderWindow *widow, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states);

    // Deconstructor
    virtual ~PauseMenuState();

    // Functions
    void endStateActions();
    void updateInput(const float &dt);
    void updateButtons();
    void update(const float &dt);
    void renderButtons(sf::RenderTarget &target);
    void render(sf::RenderTarget *target = nullptr);
};

#endif