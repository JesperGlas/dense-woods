#include "Gui.hpp"

/* ### === DropDownSelect === ### */

/* === Private Functions === */
void gui::DropDownSelect::initBackground()
{
    this->m_background.setSize(this->m_closedSize);
    this->m_background.setPosition(this->m_position);
    this->m_background.setFillColor(this->m_backgroundColor);
}

/* === Constructor === */
gui::DropDownSelect::DropDownSelect(
    const float x,
    const float y,
    const float width,
    const float height,
    const sf::Font &font
) : mref_font {font},
    mptr_active {nullptr},
    m_backgroundColor {sf::Color(50, 50, 50)},
    m_keytime {0.f},
    m_keytimeMax {10.f},
    m_isOpen {false},
    m_position {sf::Vector2f(x, y)},
    m_closedSize {sf::Vector2f(width, height)},
    m_openSize {sf::Vector2f(width, height * 2)}
{
    std::clog << "Constructing DropDownSelect object.." << std::endl;

    std::clog << "DropDownSelect object constructed!" << std::endl;
}

/* === Deconstructor === */
gui::DropDownSelect::~DropDownSelect()
{
    delete this->mptr_active;

    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }
}

/* === Getters === */
const std::string &gui::DropDownSelect::getSelected() const
{
    return this->m_activeCode;
}

const bool gui::DropDownSelect::getKeytime()
{
    if (this->m_keytime >= this->m_keytimeMax)
    {
        this->m_keytime = 0.f;
        return true;
    }

    return false;
}

/* === Setters === */
void gui::DropDownSelect::addAlternative(std::string key, std::string text)
{
    // Add button
    if (m_buttons.empty())
    {
        this->mptr_active = new Button(
            this->m_position.x,
            this->m_position.y,
            this->m_closedSize.x,
            this->m_closedSize.y,
            this->mref_font,
            12,
            text
        );

        this->m_activeCode = key;
        this->initBackground();
    }

    this->m_buttons[key] = new Button(
        this->m_position.x,
        this->m_position.y + this->m_closedSize.y + this->m_closedSize.y * this->m_buttons.size(),
        this->m_closedSize.x,
        this->m_closedSize.y,
        this->mref_font,
        12,
        text
    );

    // Add alternative in list
    this->m_items[key] = text;
    this->m_openSize.y += this->m_closedSize.y;
}

/* === Functions === */

void gui::DropDownSelect::render(sf::RenderTarget &target)
{
    if (this->mptr_active && !this->m_buttons.empty())
    {
        target.draw(this->m_background);

        this->mptr_active->render(target);

        if (this->m_isOpen)
        {
            for (auto &iter : this->m_buttons)
            {
                iter.second->render(target);
            }
        }
    }
}

void gui::DropDownSelect::updateBackgroud()
{
    if (this->m_isOpen)
        this->m_background.setSize(this->m_openSize);
    else
        this->m_background.setSize(this->m_closedSize);
}

void gui::DropDownSelect::updateKeytime(const float &dt)
{
    if (this->m_keytime < this->m_keytimeMax)
    {
        this->m_keytime += 100.f * dt;
    }
}

void gui::DropDownSelect::updateButtons(const sf::Vector2f &mouse_position)
{
    this->mptr_active->update(mouse_position);

    if (this->m_isOpen)
    {
        for (auto &iter : this->m_buttons)
        {
            iter.second->update(mouse_position);
        }
    }
}

void gui::DropDownSelect::updateInput(const float &dt)
{
    if (this->mptr_active->isActive() && this->getKeytime())
    {
        this->m_isOpen = !this->m_isOpen;
    }

    if (this->m_isOpen)
    {
        for (auto &iter : this->m_buttons)
        {
            if (iter.second->isActive())
            {
                this->m_activeCode = iter.first;
                this->mptr_active->setText(this->m_items[iter.first]);
            }
        }
    }
}

void gui::DropDownSelect::update(const float &dt, const sf::Vector2f &mouse_position)
{
    this->updateKeytime(dt);

    this->updateBackgroud();

    this->updateButtons(mouse_position);

    this->updateInput(dt);
}

/* ### === End DropDownSelect === ### */