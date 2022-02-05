#include "MovementComponent.hpp"

void MovementComponent::initVariables()
{

}

/* ### Constructors ### */
MovementComponent::MovementComponent(
    sf::Sprite &sprite,
    const float acceleration,
    const float deceleration,
    const float max_velocity
    ) : mref_sprite {sprite},
        m_velocity {sf::Vector2f(0.f, 0.f)},
        m_acceleration {sf::Vector2f(acceleration, acceleration)},
        m_deceleration {sf::Vector2f(deceleration, deceleration)},
        m_maxVelocity {sf::Vector2f(max_velocity, max_velocity)}
{
    std::clog << "Constructing MovementComponent.." << std::endl;

    this->initVariables();

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

void MovementComponent::setVelocity(sf::Vector2f velocity)
{
    this->m_velocity = velocity;
}

void MovementComponent::setUniformAcceleration(const float acceleration)
{
    this->m_acceleration.x = acceleration;
    this->m_acceleration.y = acceleration;
}

void MovementComponent::setUniformDeceleration(const float deceleration)
{
    this->m_deceleration.x = deceleration;
    this->m_deceleration.y = deceleration;
}


/* === Public Functions === */
void MovementComponent::move(const float &dt, const sf::Vector2f direction)
{
    this->move(dt, direction.x, direction.y);
}

void MovementComponent::move(const float &dt, const float x_dir, const float y_dir)
{
    // Acceleration
    /* TODO: Could this be done more efficiently? */
    this->m_velocity.x += this->m_acceleration.x * x_dir;
    if (abs(this->m_velocity.x) > this->m_maxVelocity.x) {
        int direction = (this->m_velocity.x >= 0) ? 1 : -1;
        this->m_velocity.x = this->m_maxVelocity.x * direction;
    }

    this->m_velocity.y += this->m_acceleration.y * y_dir;
    if (abs(this->m_velocity.y) > this->m_maxVelocity.y)
    {
        int direction = (this->m_velocity.y >= 0) ? 1 : -1;
        this->m_velocity.y = this->m_maxVelocity.y * direction;
    }
}

void MovementComponent::update(const float &dt)
{
    // Decelaration
    if (abs(this->m_velocity.x) > 0)
    {
        int direction = (this->m_velocity.x >= 0) ? 1 : -1;
        this->m_velocity.x -= this->m_deceleration.x * direction;
    }

    if (abs(this->m_velocity.y) > 0)
    {
        int direction = (this->m_velocity.y >= 0) ? 1 : -1;
        this->m_velocity.y -= this->m_deceleration.y * direction;
    }

    // Move sprite
    this->mref_sprite.move(this->m_velocity * dt);
}