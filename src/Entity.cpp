#include "Entity.hpp"

/* ### Private Functions */
void Entity::initVariables()
{
    
}

// Constructors
Entity::Entity()
    : m_moveSpeed {100.f}
{
    std::clog << "Constructing Entity object.." << std::endl;
    
    this->initVariables();
    
    std::clog << "Entity object constructed!" << std::endl;
}

// Deconstructor
Entity::~Entity()
{
    std::clog << "Deconstructing Entity object.." << std::endl;

    delete this->mptr_sprite;

    std::clog << "Entity object deconstructed!" << std::endl;
}

/* ### Component Functions */
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
void Entity::move(const float &dt, const float x_offset, const float y_offset)
{
    this->move(dt, sf::Vector2f(x_offset, y_offset));
}

void Entity::move(const float &dt, const sf::Vector2f offset)
{
    if (this->mptr_sprite)
    {
        this->mptr_sprite->move(offset * this->m_moveSpeed * dt);
    }
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