#include "Player.hpp"

/* ### Private Functions ### */
void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMovementComponent(100.f);
}

// Constructor
Player::Player(float x, float y, sf::Texture *texture)
    : Entity ()
{
    std::clog << "Constructing Player object.." << std::endl;

    this->initComponents();

    this->createSprite(texture);
    this->setPosition(x, y);
    this->mptr_sprite->setScale(0.2, 0.2);

    // Center origin
    this->mptr_sprite->setOrigin(
        this->mptr_sprite->getLocalBounds().width/2,
        this->mptr_sprite->getLocalBounds().height/2
    );

    std::clog << "Player object constructed!" << std::endl;
}

Player::Player(sf::Vector2f position, sf::Texture *texture)
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