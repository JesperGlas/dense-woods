#include "MovementComponent.hpp"


/* ### Constructors ### */
MovementComponent::MovementComponent(sf::Vector2f max_velocity)
    : m_maxVelocity {max_velocity}
{
    std::clog << "Constructing MovementComponent.." << std::endl;

    std:: clog << "Movementcomponent constructed!" << std:: endl;
}


/* ### Deconstructors ### */
MovementComponent::~MovementComponent()
{
    std::clog << "Deconstructing MovementComponent.." << std::endl;

    std::clog << "MovementComponent deconstructed!" << std::endl;
}

/* === Getters === */
const sf::Vector2f & MovementComponent::getVelocity() const
{
    return this->m_velocity;
}

const sf::Vector2f & MovementComponent::getMaxVelocity() const
{
    return this->m_maxVelocity;
}

/* === Setters === */
void MovementComponent::setMaxVelocity(sf::Vector2f velocity)
{
    this->m_maxVelocity = velocity;
}

/* === Public Functions === */
void MovementComponent::move(const sf::Vector2f direction)
{
    this->move(direction.x, direction.y);
}

void MovementComponent::move(const float x_dir, const float y_dir)
{
    this->m_velocity.x = this->m_maxVelocity.x * x_dir;
    this->m_velocity.y = this->m_maxVelocity.y * y_dir;
}

void MovementComponent::update(const float &dt)
{

}