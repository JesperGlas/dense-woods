#ifndef _MAINMENUSTATE_
#define _MAINMENUSTATE_

#include "State.hpp"
#include "GameState.hpp"
#include "Button.hpp"

class MainMenuState
    : public State
{
// Variables
private:
    sf::Texture m_backgroundTexture;
    sf::RectangleShape m_background;
    sf::RectangleShape m_titleBackground;
    sf::Text m_title;

    std::map<std::string, Button *> m_buttons;
public:

// Functions
private:
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();
public:
    // Constructor
    MainMenuState(sf::RenderWindow *widow, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states);

    // Deconstructor
    virtual ~MainMenuState();

    // Functions
    void endStateActions();
    void updateInput(const float &dt);
    void updateButtons();
    void update(const float &dt);
    void renderButtons(sf::RenderTarget *target = nullptr);
    void render(sf::RenderTarget *target = nullptr);
};

#endif