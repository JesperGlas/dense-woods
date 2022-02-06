#include "HitboxComponent.hpp"

/* === Private functions === */

/* === Constructors === */

HitboxComponent::HitboxComponent(
    sf::Sprite &sprite,
    const float x_offset,
    const float y_offset,
    const float width,
    const float height
) : mref_sprite {sprite}, m_offset {sf::Vector2f(x_offset, y_offset)}
{
    std::clog << "Constructing HitboxComponent object.." << std::endl;

    this->m_hitbox.setPosition(this->mref_sprite.getPosition() + this->m_offset);
    this->m_hitbox.setSize(sf::Vector2f(width, height));

    this->m_hitbox.setFillColor(sf::Color::Transparent);
    this->m_hitbox.setOutlineThickness(1.f);
    this->m_hitbox.setOutlineColor(sf::Color::Red);

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
    this->m_hitbox.setPosition(this->mref_sprite.getPosition() + this->m_offset);
}

void HitboxComponent::render(sf::RenderTarget &target)
{
    target.draw(this->m_hitbox);
} 