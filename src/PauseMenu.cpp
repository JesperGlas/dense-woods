#include "PauseMenu.hpp"

/* === Private functions === */
void PauseMenu::initButtons()
{

}

/* === Constructors === */
PauseMenu::PauseMenu(sf::RenderWindow &window)
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
            window.getSize().x/4.f,
            window.getSize().y
        )
    );
    this->m_container.setFillColor(sf::Color(36, 36, 36, 255));
    this->m_container.setPosition(0.f, 0.f);
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
void PauseMenu::update()
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

    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target); 
    }
}