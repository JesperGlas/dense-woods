#include "Gui.hpp"

/* ### === Button === ### */

// Constructor
gui::Button::Button(
    const float x, const float y,
    const float width, const float heigth,
    const sf::Font & font, 
    const unsigned char_size,
    std::string text,
    sf::Color idle_color_fill,
    sf::Color idle_color_text,
    sf::Color hover_color_fill,
    sf::Color hover_color_text,
    sf::Color active_color_fill,
    sf::Color active_color_text
    ) : m_buttonState {BTN_IDLE},
        mref_font {font},
        m_charSize {char_size},
        m_idleColorFill {idle_color_fill},
        m_hoverColorFill {hover_color_fill},
        m_activeColorFill {active_color_fill},
        m_idleColorText {idle_color_text},
        m_hoverColorText {hover_color_text},
        m_activeColorText {active_color_text}
{
    std::clog << "Constructing Button object.." << std::endl;
    
    this->m_shape.setPosition(sf::Vector2f(x, y));
    this->m_shape.setSize(sf::Vector2f(width, heigth));

    this->m_text.setFont(this->mref_font);
    this->m_text.setString(text);
    this->m_text.setFillColor(sf::Color::White);
    this->m_text.setCharacterSize(char_size);
    this->m_text.setPosition(
        x + this->m_shape.getLocalBounds().width/10,
        y + this->m_shape.getLocalBounds().height/2 - this->m_text.getLocalBounds().height/2
    );

    this->m_shape.setFillColor(this->m_idleColorFill);

    std::clog << "Button object constructed!" << std::endl;
}

gui::Button::Button(
    const float x, const float y,
    const float width, const float height,
    const sf::Font & font,
    const unsigned char_size,
    std::string text
) : Button(
    x, y, width, height,
    font, char_size, text,
    sf::Color::Transparent,
    sf::Color::White,
    sf::Color(50, 50, 50),
    sf::Color::White,
    sf::Color(50, 50, 50),
    sf::Color::Black
    )
{
    std::clog << "Constructing standard button.." << std::endl;

    std::clog << "Standard button constructed!" << std::endl;
}

gui::Button::Button(
    const float x, const float y,
    const sf::Font &font,
    std::string text
) : Button(
    x, y, 100.f, 50.f,
    font, 20, text
    )
{

}

// Deconstructor
gui::Button::~Button()
{
    std::clog << "Button object deconstructed.." << std::endl;
}

/* === Getters === */
const bool gui::Button::isActive() const
{
    return this->m_buttonState == BTN_ACTIVE;
}

const sf::Vector2f &gui::Button::getSize() const
{
    return this->m_shape.getSize();
}

const float &gui::Button::getWidth() const
{
    return this->getSize().x;
}

const float &gui::Button::getHeight() const
{
    return this->getSize().y;
}

/* === Setters === */

void gui::Button::setText(std::string text)
{
    this->m_text.setString(text);
}

// Functions
void gui::Button::update(const sf::Vector2f mousePos)
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
        this->m_shape.setFillColor(m_idleColorFill);
        this->m_text.setFillColor(m_idleColorText);
        break;
    case BTN_HOVER:
        this->m_shape.setFillColor(m_hoverColorFill);
        this->m_text.setFillColor(m_hoverColorText);
        break;
    case BTN_ACTIVE:
        this->m_shape.setFillColor(m_activeColorFill);
        this->m_text.setFillColor(m_activeColorText);
        break;
    default:
        break;
    }
}

void gui::Button::render(sf::RenderTarget &target)
{
    target.draw(this->m_shape);
    target.draw(this->m_text);
}

/* ### === End Button === ### */