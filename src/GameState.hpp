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
public:

// Functions
private:
    void initFonts();
    void initKeybinds();
    void initTextures();
    void initPlayer();
    void initObjects();
public:
    // Constructor
    GameState(sf::RenderWindow *widow, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states);

    // Deconstructor
    virtual ~GameState();

    // Functions
    void endStateActions();
    void updateInput(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget *target = nullptr);
};

#endif