#ifndef _PLAYER_
#define _PLAYER_

#include "Entity.hpp"

class Player
    : public Entity
{
// Variable
private:
public:

// Functions
private:
    void initVariables();
    void initComponents();

public:
    // Constructor
    Player(float x, float y, sf::Texture *texture);
    Player(sf::Vector2f position, sf::Texture *texture);

    // Deconstructor
    virtual ~Player();

    // Functions
    void rotate(const float &dt, float offset);
};

#endif