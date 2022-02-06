#include "HitboxComponent.hpp"

/* === Private functions === */

/* === Constructors === */

HitboxComponent::HitboxComponent(
    sf::Sprite &sprite,
    const float x_start_offset,
    const float y_start_offset,
    const float x_end_offset,
    const float y_end_offset
) : mref_sprite {sprite}, m_posOffset {sf::Vector2f(x_start_offset, y_start_offset)}
{
    std::clog << "Constructing HitboxComponent object.." << std::endl;

    this->m_hitbox.setPosition(this->mref_sprite.getPosition() + this->m_posOffset);
    this->m_hitbox.setSize(sf::Vector2f(
        this->mref_sprite.getGlobalBounds().width + x_end_offset,
        this->mref_sprite.getGlobalBounds().height + y_end_offset
    ));

    this->m_hitbox.setFillColor(sf::Color::Transparent);
    this->m_hitbox.setOutlineThickness(1.f);
    this->m_hitbox.setOutlineColor(sf::Color::Green);

    std::clog << "HitboxComponent object constructed!" << std::endl;
}

/* === Deconstructors === */

HitboxComponent::~HitboxComponent()
{
    std::clog << "Deconstructing HitboxComponent.." << std::endl;

    std::clog << "HitboxComponent deconstructed!" << std::endl;
}

/* === Functions === */

bool HitboxComponent::checkCollision(const sf::FloatRect &rect)
{
    return this->m_hitbox.getGlobalBounds().intersects(rect);
}

void HitboxComponent::update()
{
    this->m_hitbox.setPosition(this->mref_sprite.getPosition() + this->m_posOffset);
}

void HitboxComponent::render(sf::RenderTarget *target)
{
    target->draw(this->m_hitbox);
} 