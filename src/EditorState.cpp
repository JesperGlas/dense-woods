#include "EditorState.hpp"

// Constructors
EditorState::EditorState(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
{
    std::clog << "Constructing EditorState object.." << std::endl;

    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    m_title.setFillColor(sf::Color::White);
    m_title.setFont(this->m_font);
    m_title.setString("Editor");
    m_title.setCharacterSize(40);
    m_title.setPosition(sf::Vector2f(40.f, 500.f));

    std::clog << "EditorState object constructed!" << std::endl;
}

// Deconstructors
EditorState::~EditorState()
{
    std::clog << "Deconstructing EditorState object.." << std::endl;

    // Deconstruct buttons using an iterator
    for (auto &iter : this->m_buttons)
    {
        delete iter.second;
    }

    std::clog << "EditorState object deconstructed!" << std::endl;
}

// Private Functions
void EditorState::initVariables()
{

}

void EditorState::initBackground()
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

void EditorState::initKeybinds()
{
    this->setKeybind("CLOSE", this->getSupportedKey("A"));
}

void EditorState::initButtons()
{
    this->m_buttons["EXIT_STATE"] = new Button(
        40.f, 760.f,
        this->m_font, "Back"
    );
}

// Public Functions
void EditorState::endStateActions()
{
    std::clog << "Performing endStateActions on EditorState.." << std::endl;
}

void EditorState::updateInput(const float &dt)
{
    if (this->m_buttons["EXIT_STATE"]->isActive())
    {
        this->setStateEnd();
    }
}

void EditorState::updateButtons()
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->update(this->getMousePosView());
    }
}

void EditorState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateKeyTime(dt);

    this->updateButtons();

    this->updateInput(dt);
}

void EditorState::renderButtons(sf::RenderTarget &target)
{
    for (auto &iter : this->m_buttons)
    {
        iter.second->render(target);
    }
}

void EditorState::render(sf::RenderTarget *target)
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

