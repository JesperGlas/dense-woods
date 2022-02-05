#include "Entity.hpp"

/* ### Private Functions */
void Entity::initVariables()
{
    
}

// Constructors
Entity::Entity()
    : mptr_movementComponent {nullptr}
{
    std::clog << "Constructing Entity object.." << std::endl;
    
    this->initVariables();
    
    std::clog << "Entity object constructed!" << std::endl;
}

// Deconstructor
Entity::~Entity()
{
    std::clog << "Deconstructing Entity object.." << std::endl;

    if (this->mptr_movementComponent)
    {
        delete this->mptr_movementComponent;
    }

    std::clog << "Entity object deconstructed!" << std::endl;
}

/* ### Component Functions */
void Entity::createMovementComponent(
    const float acceleration,
    const float deceleration,
    const float max_velocity
)
{
    this->mptr_movementComponent = new MovementComponent(
        this->m_sprite,
        acceleration,
        deceleration,
        max_velocity);
}

void Entity::setSpriteTexture(sf::Texture &texture)
{
    this->m_sprite.setTexture(texture);
}


// Functions
void Entity::setPosition(const float x, const float y)
{
    this->m_sprite.setPosition(x, y);
}

void Entity::centerOrigin()
{
    this->m_sprite.setOrigin(sf::Vector2f(
        this->m_sprite.getLocalBounds().width/2,
        this->m_sprite.getLocalBounds().height/2
    ));
}

void Entity::setUniformScale(const float scale)
{
    this->m_sprite.setScale(sf::Vector2f(scale, scale));
}

void Entity::move(const float x_dir, const float y_dir, const float &dt)
{
    if (this->mptr_movementComponent)
    {
        this->mptr_movementComponent->move(dt, x_dir, y_dir);
    }
}

void Entity::move(const sf::Vector2f direction, const float &dt)
{
    this->move(direction.x, direction.y, dt);
}

void Entity::update(const float &dt)
{
    if (this->mptr_movementComponent)
    {
        this->mptr_movementComponent->update(dt);
    }
}

void Entity::render(sf::RenderTarget *target)
{
    target->draw(this->m_sprite);
}