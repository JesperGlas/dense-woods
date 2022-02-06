#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "MovementComponent.hpp"
#include "HitboxComponent.hpp"

class Entity
{
// Variables
private:
protected:
    sf::Sprite m_sprite;

    HitboxComponent *mptr_hitboxComponent;
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
    void setSpriteTexture(sf::Texture &texture);
    void createMovementComponent(
        const float acceleration,
        const float deceleration,
        const float maxVelocity);

    // Functions
    virtual void setPosition(const float x, const float y);
    virtual void centerOrigin();
    virtual void setUniformScale(const float scale);
    virtual void move(const float x_dir, const float y_dir, const float &dt);
    virtual void move(const sf::Vector2f direction, const float &dt);
    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);
};

#endif