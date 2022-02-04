#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Entity
{
// Variables
private:
    sf::RectangleShape m_shape;
    float m_moveSpeed;
public:

// Functions
private:
public:
    // Constructor
    Entity();

    // Deconstructor
    virtual ~Entity();

    // Functions
    virtual void move(const float &dt, const float x, const float y);
    virtual void move(const float &dt, const sf::Vector2f position);
    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);
};

#endif