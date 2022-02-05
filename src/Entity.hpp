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
protected:
    float m_moveSpeed;
    sf::Sprite *mptr_sprite;
    sf::Texture *mptr_texture;
public:

// Functions
private:
    void initVariables();
public:
    // Constructor
    Entity();

    // Deconstructor
    virtual ~Entity();

    // Component Functions
    void createSprite(sf::Texture *texture);

    // Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float &dt, const float x, const float y);
    virtual void move(const float &dt, const sf::Vector2f position);
    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);
};

#endif