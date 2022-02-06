#include "MainMenuState.hpp"

// Constructors
MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
{
    std::clog << "Constructing MainMenuState object.." << std::endl;

    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    m_title.setFillColor(sf::Color::White);
    m_title.setFont(this->m_font);
    m_title.setString("Sub Surface");
    m_title.setCharacterSize(40);
    m_title.setPosition(sf::Vector2f(40.f, 500.f));

    std::clog << "MainMenuState object constructed!" << std::endl;
}

// Deconstructors
MainMenuState::~MainMenuState()
{
    std::clog << "Deconstructing MainMenuState object.." << std::endl;

    // Deconstruct buttons using an iterator
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }

    std::clog << "MainMenuState object deconstructed!" << std::endl;
}

// Private Functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
    // Load background texture
    if (!this->m_backgroundTexture.loadFromFile("assets/img/menu_2.jpg"))
    {
        throw("ERROR: Can't load background texture!");
    }

    this->m_backgroundTexture.setSmooth(true);
    this->m_background.setSize(sf::Vector2f(this->getWindow()->getSize()));
    this->m_background.setTexture(&this->m_backgroundTexture);
}

void MainMenuState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("A"));
}

void MainMenuState::initButtons()
{
    this->m_buttons["GAME_STATE"] = new Button(
        40.f, 580.f,
        &this->m_font, "Continue"
    );

    // TODO: Implement function for button
    this->m_buttons["SETTINGS_STATE"] = new Button(
        40.f, 640.f,
        &this->m_font, "Settings"
    );

    // TODO: Implement function for button
    this->m_buttons["EDITOR_STATE"] = new Button(
        40.f, 700.f,
        &this->m_font, "Editor"
    );

    this->m_buttons["EXIT_STATE"] = new Button(
        40.f, 760.f,
        &this->m_font, "Quit"
    );
}

// Public Functions
void MainMenuState::endStateActions()
{
    std::clog << "Performing endStateActions on MainMenuState.." << std::endl;
}

void MainMenuState::updateInput(const float &dt)
{
    
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
        this->addState(
            new GameState(
                this->getWindow(),
                this->getSupportedKeys(),
                this->getStateStack()
            )
        );
    }

    // Editor
    if (this->m_buttons["EDITOR_STATE"]->isActive())
    {
        this->addState(
            new EditorState(
                this->getWindow(),
                this->getSupportedKeys(),
                this->getStateStack()
            )
        );
    }

    // Quit Game
    if (this->m_buttons["EXIT_STATE"]->isActive())
    {
        std::clog << "### Quit toggle btn ###" << std::endl;
        this->signalStateEnd();
    }
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateButtons();
    this->updateInput(dt);
}

void MainMenuState::renderButtons(sf::RenderTarget &target)
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

