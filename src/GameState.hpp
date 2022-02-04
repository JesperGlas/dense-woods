#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include "State.hpp"

class GameState
    : public State
{
// Variables
private:
public:

// Functions
private:
public:
    // Constructor
    GameState(sf::RenderWindow *widow);

    // Deconstructor
    virtual ~GameState();

    // Functions
    void endStateActions();
    void updateKeyBinds(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget *mptr_target = nullptr);
};

#endif