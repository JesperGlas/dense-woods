#include "MainMenuState.hpp"

// Constructors
MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
{
    std::clog << "Constructing MainMenuState object.." << std::endl;
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    sf::Vector2u window_size = this->getWindow()->getSize();
    m_titleBackground.setFillColor(sf::Color::Cyan);
    m_titleBackground.setSize(sf::Vector2f(
        window_size.x/4,
        window_size.y-200));
    m_titleBackground.setPosition(100.f, 100.f);

    m_title.setFillColor(sf::Color::White);
    m_title.setFont(this->m_font);
    m_title.setString("Sub Surface");
    m_title.setCharacterSize(40);
    m_title.setPosition(sf::Vector2f(
        140.f, 140.f
    ));

    std::clog << "MainMenuState object constructed!" << std::endl;
}

// Deconstructors
MainMenuState::~MainMenuState()
{
    // Deconstruct buttons using an iterator
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }
    std::clog << "MainMenuState object deconstructed.." << std::endl;
}

// Private Functions
void MainMenuState::initFonts()
{
    this->setFont("assets/fonts/Roboto/roboto/Roboto-Regular.ttf");
}

void MainMenuState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("A"));
}

void MainMenuState::initButtons()
{
    this->m_buttons["EXIT_STATE"] = new Button(
        140.f, this->getWindow()->getSize().y - 200.f,
        100.f, 40.f,
        &this->m_font, "Quit"
    );

    this->m_buttons["GAME_STATE"] = new Button(
        140.f, this->getWindow()->getSize().y - 260.f,
        100.f, 40.f,
        &this->m_font, "Continue"
    );

}

// Public Functions
void MainMenuState::endStateActions()
{
    std::clog << "Performing endStateActions on MainMenuState.." << std::endl;
}

void MainMenuState::updateInput(const float &dt)
{
    this->checkForQuit();
}

void MainMenuState::updateButtons()
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->update(this->getMousePosView());
    }

    // Start Game
    if (this->m_buttons["GAME_STATE"]->isActive())
    {
        this->addState(new GameState(
            this->getWindow(),
            this->getSupportedKeys(),
            this->getStateStack()
        ));
    }

    // Quit Game
    if (this->m_buttons["EXIT_STATE"]->isActive())
    {
        std::clog << "### Quit toggle btn ###" << std::endl;
        this->setQuit(true);
    }
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateButtons();
    this->updateInput(dt);
}

void MainMenuState::renderButtons(sf::RenderTarget *target)
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->getWindow();
    }

    target->draw(this->m_titleBackground);
    target->draw(this->m_title);
    this->renderButtons(target);
}

