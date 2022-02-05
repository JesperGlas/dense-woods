#include "Player.hpp"

/* ### Private Functions ### */
void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMovementComponent(
        5.f,
        1.f,
        200.f
    );
}

// Constructor
Player::Player(float x, float y, sf::Texture &texture)
    : Entity ()
{
    std::clog << "Constructing Player object.." << std::endl;

    this->initComponents();

    this->setSpriteTexture(texture);
    this->setPosition(x, y);
    this->setUniformScale(0.2);
    this->centerOrigin();

    std::clog << "Player object constructed!" << std::endl;
}

Player::Player(sf::Vector2f position, sf::Texture &texture)
    : Player(position.x, position.y, texture)
{

}


// Deconstructor
Player::~Player()
{
    std:: clog << "Constructing Player object.." << std::endl;

    std::clog << "Player object deconstructed!" << std::endl;
}

// Functions