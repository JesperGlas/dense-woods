#ifndef _STATE_HPP_
#define _STATE_HPP_

#include "Entity.hpp"
#include "Button.hpp"

class State
{
// Variables
private:
    sf::RenderWindow *mptr_window;
    std::map<std::string, sf::Keyboard::Key> *mptr_supportedKeys;
    std::stack<State *> *mptr_states;
    
    bool m_stateEndSignal;
    bool m_statePauseSignal;
    float m_keytime;
    float m_keytimeMax;

    std::map<std::string, sf::Keyboard::Key> m_keyBinds;
    sf::Vector2i m_mousePosScreen; // Mouse position on screen
    sf::Vector2i m_mousePosWindow; // Mouse position on window
    sf::Vector2f m_mousePosView; // Mouse position relative to view
protected:
    sf::Font m_font; // TODO: Make getter work, move to private
    std::map<std::string, sf::Texture> m_textures;
    
public:

// Functions
private:
protected:
    virtual void initFonts();
    
    virtual void initKeybinds() = 0;
public:
    // Constructors
    State(sf::RenderWindow *window, std::map<std::string, sf::Keyboard::Key> *supportedKeys, std::stack<State *> *states);

    // Deconstructors
    virtual ~State();

    // Getters
    sf::RenderWindow * getWindow(); // Original sf::RenderWindow * getWindow()
    std::map<std::string, sf::Keyboard::Key> * getSupportedKeys();
    std::stack<State *> * getStateStack();
    const sf::Keyboard::Key & getSupportedKey(std::string key);
    const sf::Keyboard::Key & getKeyBind(std::string key);
    const sf::Vector2i & getMousePosScreen();
    const sf::Vector2i & getMousePosWindow();
    const sf::Vector2f & getMousePosView();
    sf::Font & getFont();

    // Setters
    void setKeybind(std::string action, sf::Keyboard::Key key);
    void setFont(std::string path);
    void setStateEnd();
    void setStatePause(bool state);
    void addState(State *state);

    void addTexture(std::string name, std::string path);

    // Getters
    const sf::Texture & getTexture(std::string name) const;
    const bool & checkIfStateEnd() const;
    const bool & checkIfStatePaused() const;
    const bool getKeytime();

    // Functions
    virtual void updateMousePositions();
    virtual void updateKeyTime(const float &dt);

    virtual void endStateActions() = 0;
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *mptr_target = nullptr) = 0;
};

#endif