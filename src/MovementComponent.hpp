#ifndef _MOVEMENT_COMPONENT_HPP_
#define _MOVEMENT_COMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class MovementComponent
{
private:
    sf::Vector2f m_maxVelocity;
    sf::Vector2f m_velocity;
    sf::Vector2f m_acceleration;
    sf::Vector2f m_deceleration;
public:
    MovementComponent(sf::Vector2f max_velocity);

    virtual ~MovementComponent();

    // Getters
    const sf::Vector2f & getVelocity() const;
    const sf::Vector2f & getMaxVelocity() const;

    // Setters
    void setMaxVelocity(sf::Vector2f velocity);

    void move(const sf::Vector2f direction);
    void move(const float x_dir, const float y_dir);
    void update(const float &dt);
};

#endif