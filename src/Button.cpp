#include "Button.hpp"

// Constructor
Button::Button(float x, float y, float width, float heigth, sf::Font *font, std::string text)
    : m_buttonState {BTN_IDLE}, mptr_font {font}, m_idleColor {sf::Color::Black}, m_hoverColor {sf::Color::Green}, m_activeColor {sf::Color::Red}
{
    std::clog << "Constructing Button object.." << std::endl;
    
    this->m_shape.setPosition(sf::Vector2f(x, y));
    this->m_shape.setSize(sf::Vector2f(width, heigth));

    this->m_text.setFont(*this->mptr_font);
    this->m_text.setString(text);
    this->m_text.setFillColor(sf::Color::White);
    this->m_text.setCharacterSize(12);
    this->m_text.setPosition(
        this->m_shape.getPosition().x + this->m_shape.getGlobalBounds().width/2.f - this->m_text.getGlobalBounds().width/2.f,
        this->m_shape.getPosition().y + this->m_shape.getGlobalBounds().height/2.f - this->m_text.getGlobalBounds().height/2.f
    );

    this->m_shape.setFillColor(this->m_idleColor);

    std::clog << "Button object constructed!" << std::endl;
}

// Deconstructor
Button::~Button()
{
    std::clog << "Button object deconstructed.." << std::endl;
}

// Accessors
const bool Button::isActive() const
{
    return this->m_buttonState == BTN_ACTIVE;
}

// Functions
void Button::update(const sf::Vector2f mousePos)
{
    this->m_buttonState = BTN_IDLE; // Idle
    if (this->m_shape.getGlobalBounds().contains(mousePos))
    {
        this->m_buttonState = BTN_HOVER; // Hover

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->m_buttonState = BTN_ACTIVE; // Pressed
        }
    }

    switch (this->m_buttonState)
    {
    case BTN_IDLE:
        this->m_shape.setFillColor(m_idleColor);
        break;
    case BTN_HOVER:
        this->m_shape.setFillColor(m_hoverColor);
        break;
    case BTN_ACTIVE:
        this->m_shape.setFillColor(m_activeColor);
        break;
    default:
        break;
    }
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(this->m_shape);
    target->draw(this->m_text);
}
