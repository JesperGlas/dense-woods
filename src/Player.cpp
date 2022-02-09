#include "Player.hpp"

/* ### Private Functions ### */
void Player::initComponents()
{
    this->createMovementComponent(5.f, 1.f, 200.f);

    this->createHitboxComponent(
        this->m_sprite,
        4.f, 6.f,
        this->m_sprite.getGlobalBounds().width - 9.f,
        this->m_sprite.getGlobalBounds().height - 18.f
    );
}

// Constructor
Player::Player(
    float x,
    float y,
    sf::Texture &texture
    ) : Entity (),
        m_maxHealth {100.f},
        m_health {100.f}
{
    std::clog << "Constructing Player object.." << std::endl;

    this->setSpriteTexture(texture);
    this->setPosition(x, y);
    this->setUniformScale(0.2);

    this->initComponents();

    std::clog << "Player object constructed!" << std::endl;
}

Player::Player(sf::Vector2f position, sf::Texture &texture)
    : Player(position.x, position.y, texture)
{

}


// Deconstructor
Player::~Player()
{
    std::clog << "Constructing Player object.." << std::endl;

    std::clog << "Player object deconstructed!" << std::endl;
}

/* === Getters === */
const float & Player::getMaxHealth() const
{
    return this->m_maxHealth;
}

const float & Player::getHealth() const
{
    return this->m_health;
}

/* === Setters === */
void Player::setMaxHealth(float value)
{
    this->m_maxHealth = value;
}

void Player::setHealth(float value)
{
    this->m_health = value;
}

/* === Functions === */

void Player::update(const float &dt)
{
    Entity::update(dt);
}