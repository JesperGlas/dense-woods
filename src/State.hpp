#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

class State
{
// Variables
private:
    sf::RenderWindow *mptr_window;
    std::vector<sf::Texture> m_textures;
    bool m_requestQuit;
public:

// Functions
private:
public:
    // Constructors
    State(sf::RenderWindow *window);

    // Deconstructors
    virtual ~State();

    // Functions
    const bool &getQuit() const;
    virtual void checkForQuit(); // Virtual = 0 class forces us to define these functions in child classes
    virtual void endStateActions() = 0;
    virtual void updateKeyBinds(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *mptr_target = nullptr) = 0;
};

#endif