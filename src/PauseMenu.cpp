#include "PauseMenu.hpp"

/* === Private functions === */
void PauseMenu::initButtons()
{

}

/* === Constructors === */
PauseMenu::PauseMenu(sf::RenderWindow &window, sf::Font &font)
    : mref_font {font}
{
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
}

/* === Deconstructors === */
PauseMenu::~PauseMenu()
{
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }
}

/* === Functions === */
void PauseMenu::update(const sf::Vector2f &mousePosition)
{
    for (auto &iter : this->m_buttons)
    {
        // TODO: Update buttons
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