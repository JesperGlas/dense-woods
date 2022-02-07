#include "State.hpp"

/* === Private Functions === */

void State::initFonts()
{
    // Inits a default font
    this->setFont("assets/fonts/Roboto/roboto/Roboto-Regular.ttf");
}

// Constructors
State::State(
    sf::RenderWindow *window,
    std::map<std::string,
    sf::Keyboard::Key> *supportedKeys,
    std::stack<State *> *states
    ) : mptr_window {window},
        mptr_supportedKeys {supportedKeys},
        mptr_states {states},
        m_stateEndSignal {false},
        m_statePauseSignal {false},
        m_keytime {0.f},
        m_keytimeMax {10.f}
{
    std::clog << "Constructing State object.." << std::endl;

    this->setKeybind("CLOSE", this->getSupportedKey("Escape")); // Set default close key to Escape
    this->initFonts(); // Init default font
    
    std::clog << "State object constructed!" << std::endl;
}

// Deconstructors
State::~State()
{
    std::clog << "Deconstructing State object.." << std::endl;
    
    std::clog << "State object deconstructed!" << std::endl;
}

// Getters
sf::RenderWindow * State::getWindow()
{
    return this->mptr_window;
}

std::map<std::string, sf::Keyboard::Key> * State::getSupportedKeys()
{
    return this->mptr_supportedKeys;
}

std::stack<State *> * State::getStateStack()
{
    return this->mptr_states;
}

const sf::Keyboard::Key & State::getSupportedKey(std::string key)
{
    return this->mptr_supportedKeys->at(key);
}

const sf::Keyboard::Key & State::getKeyBind(std::string key)
{
    return this->m_keyBinds.at(key);
}

const sf::Vector2i & State::getMousePosScreen()
{
    return this->m_mousePosScreen;
}

const sf::Vector2i & State::getMousePosWindow()
{
    return this->m_mousePosWindow;
}

const sf::Vector2f & State::getMousePosView()
{
    return this->m_mousePosView;
}

sf::Font & State::getFont()
{
    return this->m_font;
}

/* === Setters === */

void State::setKeybind(std::string action, sf::Keyboard::Key key)
{
    this->m_keyBinds[action] = key;
}

void State::setFont(std::string path)
{
    if (!this->m_font.loadFromFile(path))
    {
        throw("ERROR: Could not load font");
    }
}

void State::setStateEnd()
{
    this->m_stateEndSignal = true;
}

void State::setStatePause(bool state)
{
    this->m_statePauseSignal = state;
}

void State::addState(State *state)
{
    this->mptr_states->push(state);
}

void State::addTexture(std::string name, std::string path)
{
    sf::Texture texture;
    if(!texture.loadFromFile(path))
    {
        throw("ERROR: Could not load texture!");
    }
    texture.setSmooth(true); // Smooth
    this->m_textures[name] = texture;

    std::clog << "Loaded texture at " << path << " to name " << name << std::endl;
}

const sf::Texture & State::getTexture(std::string name) const
{
    // TODO: Check if texture exists
    return this->m_textures.at(name);
}

/* === Getters === */

const bool & State::checkIfStateEnd() const
{
    return this->m_stateEndSignal;
}

const bool & State::checkIfStatePaused() const
{
    return this->m_statePauseSignal;
}

const bool State::getKeytime()
{
    if (this->m_keytime >= this->m_keytimeMax)
    {
        this->m_keytime = 0.f;
        return true;
    }

    return false;
}

/* === Public Functions === */

void State::updateMousePositions()
{
    this->m_mousePosScreen = sf::Mouse::getPosition();
    this->m_mousePosWindow = sf::Mouse::getPosition(*this->getWindow());
    this->m_mousePosView = this->getWindow()->mapPixelToCoords(this->m_mousePosWindow);
}

void State::updateKeyTime(const float &dt)
{
    this->m_keytime += 100.f * dt;
}