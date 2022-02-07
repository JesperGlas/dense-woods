#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

enum ButtonStates {
    BTN_IDLE = 0,
    BTN_HOVER = 1,
    BTN_ACTIVE = 2
};

class Button
{
// Variables
private:
    ButtonStates m_buttonState;
    sf::RectangleShape m_shape;

    sf::Font *mptr_font;
    unsigned m_charSize;
    sf::Text m_text;

    sf::Color m_idleColorFill;
    sf::Color m_hoverColorFill;
    sf::Color m_activeColorFill;

    sf::Color m_idleColorText;
    sf::Color m_hoverColorText;
    sf::Color m_activeColorText;

protected:
    

// Functions
public:
    // Constructor
    Button(
        const float x, const float y,
        const float width, const float heigth,
        sf::Color idle_color_fill,
        sf::Color hover_color_fill,
        sf::Color active_color_fill,
        sf::Font *font, const unsigned char_size,
        std::string text,
        sf::Color idle_color_text,
        sf::Color hover_color_text,
        sf::Color active_color_text
        );
    
    Button(
        const float x, const float y,
        const float width, const float height,
        sf::Font *font, std::string text
    );

    Button(
        const float x, const float y,
        sf::Font *font, std::string text
    );

    // Deconstructor
    ~Button();

    // Accessors
    const bool isActive() const;

    // Setters

    // Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget &target);
};

#endif