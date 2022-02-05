#ifndef _MOVEMENT_COMPONENT_HPP_
#define _MOVEMENT_COMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cmath> // Used for math

class MovementComponent
{
private:
    sf::Sprite &mref_sprite;
    sf::Vector2f m_velocity;
    sf::Vector2f m_maxVelocity;
    sf::Vector2f m_acceleration;
    sf::Vector2f m_deceleration;

private:
    void initVariables();
public:
    MovementComponent(
        sf::Sprite &sprite,
        const float acceleration,
        const float deceleration,
        const float max_velocity);

    virtual ~MovementComponent();

    // Getters
    const sf::Vector2f & getVelocity() const;
    const sf::Vector2f & getMaxVelocity() const;

    // Setters
    void setMaxVelocity(sf::Vector2f velocity);
    void setVelocity(sf::Vector2f velocity);
    void setUniformAcceleration(const float acceleration);
    void setUniformDeceleration(const float deceleration);

    void move(const float &dt, const sf::Vector2f direction);
    void move(const float &dt, const float x_dir, const float y_dir);
    void update(const float &dt);
};

#endif