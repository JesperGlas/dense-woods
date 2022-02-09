#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Entity.hpp"

class Player
    : public Entity
{
// Variable
private:
    float m_maxHealth;
    float m_health;
public:

// Functions
private:
    void initComponents();

public:
    // Constructor
    Player(float x, float y, sf::Texture &texture);
    Player(sf::Vector2f position, sf::Texture &texture);

    // Deconstructor
    virtual ~Player();

    // Getters
    const float & getMaxHealth() const;
    const float & getHealth() const;

    // Setters
    void setMaxHealth(float value);
    void setHealth(float value);

    // Functions
    void update(const float &dt);
};

#endif