#include "PauseMenuState.hpp"

// Constructors
PauseMenuState::PauseMenuState(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
{
    std::clog << "Constructing PauseMenuState object.." << std::endl;

    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    m_title.setFillColor(sf::Color::White);
    m_title.setFont(this->m_font);
    m_title.setString("Game Paused");
    m_title.setCharacterSize(40);
    m_title.setPosition(sf::Vector2f(40.f, 500.f));

    std::clog << "PauseMenuState object constructed!" << std::endl;
}

// Deconstructors
PauseMenuState::~PauseMenuState()
{
    std::clog << "Deconstructing PauseMenuState object.." << std::endl;

    // Deconstruct buttons using an iterator
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }

    std::clog << "PauseMenuState object deconstructed!" << std::endl;
}

// Private Functions
void PauseMenuState::initVariables()
{

}

void PauseMenuState::initBackground()
{
    this->m_background.setFillColor(sf::Color::Black);
    this->m_background.setSize(
        sf::Vector2f(
            this->getWindow()->getSize().x / 3.f,
            this->getWindow()->getSize().y
        )
    );
}

void PauseMenuState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("A"));
}

void PauseMenuState::initButtons()
{
    this->m_buttons["GAME_STATE"] = new Button(
        40.f, 580.f,
        &this->m_font, "Continue"
    );
}

// Public Functions
void PauseMenuState::endStateActions()
{
    std::clog << "Performing endStateActions on PauseMenuState.." << std::endl;
}

void PauseMenuState::updateInput(const float &dt)
{
    
}

void PauseMenuState::updateButtons()
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->update(this->getMousePosView());
    }

    // Start Game
    if (this->m_buttons["GAME_STATE"]->isActive())
    {
        this->setStateEnd();
    }
}

void PauseMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateButtons();
    this->updateInput(dt);
}

void PauseMenuState::renderButtons(sf::RenderTarget &target)
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target);
    }
}

void PauseMenuState::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->getWindow();
    }

    target->draw(this->m_background);
    target->draw(this->m_title);
    this->renderButtons(*target);

    /* === DEBUG FOR DESIGN ===*/
    //sf::Text mouseText;
    //mouseText.setPosition(this->getMousePosView().x, this->getMousePosView().y - 50);
    //mouseText.setFont(this->m_font);
    //mouseText.setCharacterSize(12);
    //
    //target->draw(mouseText);
}

