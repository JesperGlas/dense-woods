#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include "State.hpp"
#include "Player.hpp" // Might be bad include
#include "PauseMenu.hpp"

class GameState
    : public State
{
// Variables
private:
    PauseMenu m_pauseMenu;

    Player *mptr_player;
    sf::RectangleShape m_background;

    gui::DropDownSelect *test;
public:

// Functions
private:
    void initKeybinds();
    void initTextures();
    void initUI();
    void initPlayer();
    void initPauseMenu();
public:
    // Constructor
    GameState(
        sf::RenderWindow &widow,
        std::map<std::string, sf::Keyboard::Key> &supportedKeys,
        std::stack<State *> &states
    );

    // Deconstructor
    virtual ~GameState();

    // Functions
    void endStateActions();

    void updateInput(const float &dt);
    void updateUI(const float &dt);
    void updatePauseMenu(const float &dt);
    void updatePlayerInput(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget &target);
};

#endif