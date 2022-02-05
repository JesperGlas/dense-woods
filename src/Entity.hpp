#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "MovementComponent.hpp"

class Entity
{
// Variables
private:
protected:
    sf::Sprite *mptr_sprite;
    sf::Texture *mptr_texture;
    MovementComponent *mptr_movementComponent;
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
    void createMovementComponent(const float maxVelocity);

    // Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float &dt, const float x_dir, const float y_dir);
    virtual void move(const float &dt, const sf::Vector2f direction);
    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);
};

#endif