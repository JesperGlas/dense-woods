#include "SettingsState.hpp"

/* === Private Functions === */
void SettingsState::initVariables()
{

}

void SettingsState::initBackground()
{
    // Load background texture
    if (!this->m_backgroundTexture.loadFromFile("assets/img/menu_2.jpg"))
    {
        throw("ERROR: Can't load background texture!");
    }

    this->m_backgroundTexture.setSmooth(true);
    this->m_background.setSize(sf::Vector2f(this->getWindow().getSize()));
    this->m_background.setTexture(&this->m_backgroundTexture);
}

void SettingsState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("A"));
}

void SettingsState::initButtons()
{
    const float y_start {580.f};
    const float button_width {100.f};
    const float button_height {40.f};
    const float button_spacing {20.f};

    this->m_buttons["EXIT_STATE"] = new Button(
        40.f,
        y_start + this->m_buttons.size() * (button_height + button_spacing),
        button_width,
        button_height,
        this->m_font,
        "Quit"
    );
}

// Constructors
SettingsState::SettingsState(
    sf::RenderWindow &window,
    std::map<std::string, sf::Keyboard::Key> &supportedKeys,
    std::stack<State *> &states
    ) : State(window, supportedKeys, states)
{
    std::clog << "Constructing SettingsState object.." << std::endl;

    this->initVariables();
    this->initBackground();
    this->initKeybinds();
    this->initButtons();

    m_title.setFillColor(sf::Color::White);
    m_title.setFont(this->m_font);
    m_title.setString("Settings");
    m_title.setCharacterSize(40);
    m_title.setPosition(sf::Vector2f(40.f, 500.f));

    std::clog << "SettingsState object constructed!" << std::endl;
}

// Deconstructors
SettingsState::~SettingsState()
{
    std::clog << "Deconstructing SettingsState object.." << std::endl;

    // Deconstruct buttons using an iterator
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }

    std::clog << "SettingsState object deconstructed!" << std::endl;
}

// Public Functions
void SettingsState::endStateActions()
{
    std::clog << "Performing endStateActions on SettingsState.." << std::endl;
}

void SettingsState::updateInput(const float &dt)
{
    // Quit Game
    if (this->m_buttons["EXIT_STATE"]->isActive())
    {
        this->setStateEnd();
    }
}

void SettingsState::updateButtons()
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->update(this->getMousePosView());
    }
}

void SettingsState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateKeyTime(dt);

    this->updateInput(dt);
    this->updateButtons();
}

void SettingsState::renderButtons(sf::RenderTarget &target)
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target);
    }
}

void SettingsState::render(sf::RenderTarget &target)
{
    target.draw(this->m_background);
    target.draw(this->m_title);
    this->renderButtons(target);

    /* === DEBUG FOR DESIGN ===*/
    //sf::Text mouseText;
    //mouseText.setPosition(this->getMousePosView().x, this->getMousePosView().y - 50);
    //mouseText.setFont(this->m_font);
    //mouseText.setCharacterSize(12);
    //
    //target->draw(mouseText);
}

