#include "Gui.hpp"

/* ### === ProgressBar === ### */

/* === Private functions === */
void gui::ProgressBar::initBackground()
{
    this->m_background.setPosition(this->m_position);
    this->m_background.setSize(this->m_size);
    this->m_background.setFillColor(this->m_backgroundColor);
}

void gui::ProgressBar::initStatusBar()
{
    this->m_statusBar.setPosition(
        this->m_position + sf::Vector2f(this->m_border, this->m_border)
    );
    this->m_statusBar.setSize(   
        this->m_size - 2.f * sf::Vector2f(this->m_border, this->m_border)
    );
    this->m_statusBar.setFillColor(this->m_statusColor);
}

/* === Constructor === */
gui::ProgressBar::ProgressBar(
    const sf::Font &font,
    const float &max_value,
    const float &value,
    sf::Vector2f position,
    sf::Vector2f size,
    sf::Color color_background,
    sf::Color color_status
) : mref_font {font},
    mref_maxValue {max_value},
    mref_value {value},
    m_position {position},
    m_size {size},
    m_border {5.f},
    m_backgroundColor {color_background},
    m_statusColor {color_status}
{
    this->initBackground();
    this->initStatusBar();
}

/* === Deconstructor === */
gui::ProgressBar::~ProgressBar()
{

}

/* === Getters === */
const float & gui::ProgressBar::getValue() const
{
    return this->mref_value;
}
/* === Setters === */

/* === Update functions === */
void gui::ProgressBar::update()
{
    this->m_statusBar.setSize(
        sf::Vector2f(
            this->mref_value / this->mref_maxValue * (this->m_size.x - 2.f * this->m_border),
            this->m_size.y - 2.f * this->m_border
        )
    );
}

/* === Render functions === */
void gui::ProgressBar::render(sf::RenderTarget &target)
{
    target.draw(this->m_background);
    target.draw(this->m_statusBar);
}

/* === Functions === */

/* ### === End ProgressBar === ### */