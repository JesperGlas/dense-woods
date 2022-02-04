#include "Entity.hpp"

// Constructors
Entity::Entity()
    : m_moveSpeed {100.f}
{
    std::clog << "Constructing Entity object.." << std::endl;
    
    this->m_shape.setSize(sf::Vector2f(50.f, 50.f));
    this->m_shape.setFillColor(sf::Color::Black);
    this->m_shape.rotate(45.f);
    
    std::clog << "Entity object constructed!" << std::endl;
}

// Deconstructor
Entity::~Entity()
{
    std::clog << "Entity object deconstructed.." << std::endl;
}

// Functions
void Entity::move(const float &dt, const float x_offset, const float y_offset)
{
    this->move(dt, sf::Vector2f(x_offset, y_offset));
}

void Entity::move(const float &dt, const sf::Vector2f offset)
{
    this->m_shape.move(offset * this->m_moveSpeed * dt);
}

void Entity::update(const float &dt)
{

}

void Entity::render(sf::RenderTarget *target)
{
    target->draw(this->m_shape);
}