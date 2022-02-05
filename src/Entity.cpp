#include "Entity.hpp"

/* ### Private Functions */
void Entity::initVariables()
{
    
}

// Constructors
Entity::Entity()
    : mptr_sprite {nullptr}, mptr_texture {nullptr}, mptr_movementComponent {nullptr}
{
    std::clog << "Constructing Entity object.." << std::endl;
    
    this->initVariables();
    
    std::clog << "Entity object constructed!" << std::endl;
}

// Deconstructor
Entity::~Entity()
{
    std::clog << "Deconstructing Entity object.." << std::endl;

    if (this->mptr_sprite)
    {
        delete this->mptr_sprite;
    }
    if (this->mptr_movementComponent)
    {
        delete this->mptr_movementComponent;
    }

    std::clog << "Entity object deconstructed!" << std::endl;
}

/* ### Component Functions */
void Entity::createMovementComponent(const float maxVelocity)
{
    this->mptr_movementComponent = new MovementComponent(
        sf::Vector2f(100.f, 100.f)
    );
}

void Entity::createSprite(sf::Texture *texture)
{
    this->mptr_texture = texture;
    this->mptr_sprite = new sf::Sprite(*this->mptr_texture);
}


// Functions
void Entity::setPosition(const float x, const float y)
{
    if (this->mptr_sprite)
    {
        this->mptr_sprite->setPosition(x, y);
    }
}
void Entity::move(const float &dt, const float x_dir, const float y_dir)
{
    if (this->mptr_sprite && this->mptr_movementComponent)
    {
        // TODO: Max velocity check here or in MovementComponent
        this->mptr_movementComponent->move(x_dir, y_dir); // Sets velocity
        this->mptr_sprite->move(this->mptr_movementComponent->getVelocity() * dt); // Uses velocity
    }
}

void Entity::move(const float &dt, const sf::Vector2f direction)
{
    this->move(dt, direction.x, direction.y);
}

void Entity::update(const float &dt)
{

}

void Entity::render(sf::RenderTarget *target)
{
    if (this->mptr_sprite)
    {
        target->draw(*this->mptr_sprite);
    }
}