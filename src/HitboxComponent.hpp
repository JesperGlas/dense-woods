#ifndef _HITBOXCOMPONENT_HPP_
#define _HITBOXCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cmath> // Used for math in Movement

class HitboxComponent
{
// Variables
private:
    // TODO: Better shape
    sf::Sprite &mref_sprite;
    sf::RectangleShape m_hitbox;
    sf::Vector2f m_offset;
public:

// Functions
public:
    HitboxComponent(
        sf::Sprite &sprite,
        const float x_offset,
        const float y_offset,
        const float width,
        const float height);

    virtual ~HitboxComponent();

    bool checkCollision(const sf::FloatRect &rect);

    void update();
    void render(sf::RenderTarget &target);
};

#endif