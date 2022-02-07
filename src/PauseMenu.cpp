#include "PauseMenu.hpp"

/* === Private functions === */

/* === Constructors === */
PauseMenu::PauseMenu(sf::RenderWindow &window, sf::Font &font)
    : mref_font {font}
{
    std::clog << "Constructing PauseMenu object.." << std::endl;

    this->m_background.setPosition(0.f, 0.f);
    this->m_background.setSize(
        sf::Vector2f(
            window.getSize().x,
            window.getSize().y
        )
    );
    this->m_background.setFillColor(sf::Color(69, 69, 69, 100));

    this->m_container.setSize(
        sf::Vector2f(
            window.getSize().x/6.f,
            window.getSize().y
        )
    );
    this->m_container.setFillColor(sf::Color(36, 36, 36, 255));
    this->m_container.setPosition(0.f, 0.f);

    this->m_menuTitle.setFont(this->mref_font);
    this->m_menuTitle.setFillColor(sf::Color::White);
    this->m_menuTitle.setCharacterSize(40);
    this->m_menuTitle.setString("Pause Menu");
    this->m_menuTitle.setPosition(
        this->m_container.getPosition() + sf::Vector2f(40.f, 40.f)
    );

    std::clog << "PauseMenu object constructed!" << std::endl;
}

/* === Deconstructors === */
PauseMenu::~PauseMenu()
{
    std::clog << "Deconstructing PauseMenu object.." << std::endl;

    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }

    std::clog << "PauseMenu object deconstructed!" << std::endl;
}

/* === Getters === */
const bool PauseMenu::isButtonPressed(const std::string key)
{
    // Count to check if key exists
    if (this->m_buttons.count(key))
        return this->m_buttons.at(key)->isActive();
    else
        return false;
}

/* === Functions === */

void PauseMenu::addButton(std::string key, std::string text)
{
    const float button_start_y {100.f};
    const float button_width {120.f};
    const float button_height {40.f};
    const float button_spacing {20.f};

    this->m_buttons[key] = new Button(
        40.f,
        button_start_y + this->m_buttons.size() * (button_height + button_spacing),
        button_width,
        button_height,
        &this->mref_font,
        text
    );
}

void PauseMenu::update(const sf::Vector2f &mousePosition)
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->update(mousePosition);
    }

}

void PauseMenu::render(sf::RenderTarget &target)
{
    target.draw(this->m_background);
    target.draw(this->m_container);
    target.draw(this->m_menuTitle);

    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target); 
    }
}