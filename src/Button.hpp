#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

enum button_states{
    BTN_IDLE = 0,
    BTN_HOVER = 1,
    BTN_ACTIVE = 2
    };

class Button
{
// Variables
private:
    short unsigned m_buttonState;
    sf::RectangleShape m_shape;
    sf::Font *mptr_font;
    sf::Text m_text;

    sf::Color m_idleColor;
    sf::Color m_hoverColor;
    sf::Color m_activeColor;

protected:
    

// Functions
public:
    // Constructor
    Button(float x, float y, float width, float heigth, sf::Font *font, std::string text);

    // Deconstructor
    ~Button();

    // Accessors
    const bool isActive() const;


    // Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget *target);
};

#endif