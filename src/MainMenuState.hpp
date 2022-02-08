#ifndef _MAINMENUSTATE_HPP_
#define _MAINMENUSTATE_HPP_

#include "GameState.hpp"
#include "EditorState.hpp"
#include "SettingsState.hpp"

class MainMenuState
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
    MainMenuState(
        sf::RenderWindow &widow,
        std::map<std::string, sf::Keyboard::Key> &supportedKeys,
        std::stack<State *> &states
    );

    // Deconstructor
    virtual ~MainMenuState();

    // Functions
    void endStateActions();
    void updateInput(const float &dt);
    void updateButtons();
    void update(const float &dt);
    void renderButtons(sf::RenderTarget &target);
    void render(sf::RenderTarget &target);
};

#endif