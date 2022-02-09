#ifndef _GUI_HPP_
#define _GUI_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <any>

enum ButtonStates {
    BTN_IDLE = 0,
    BTN_HOVER = 1,
    BTN_ACTIVE = 2
};

namespace gui {
    class Button
    {
    // Variables
    private:
        ButtonStates m_buttonState;
        sf::RectangleShape m_shape;

        const sf::Font &mref_font;
        unsigned m_charSize;
        sf::Text m_text;

        sf::Color m_idleColorFill;
        sf::Color m_hoverColorFill;
        sf::Color m_activeColorFill;

        sf::Color m_idleColorText;
        sf::Color m_hoverColorText;
        sf::Color m_activeColorText;

    // Functions
    public:
        // Constructor
        Button(
            const float x, const float y,
            const float width, const float heigth,
            const sf::Font & font,
            const unsigned char_size,
            std::string text,
            sf::Color idle_color_fill,
            sf::Color idle_color_text,
            sf::Color hover_color_fill,
            sf::Color hover_color_text,
            sf::Color active_color_fill,
            sf::Color active_color_text
            );
        
        Button(
            const float x, const float y,
            const float width, const float height,
            const sf::Font & font,
            const unsigned char_size,
            std::string text
        );

        Button(
            const float x, const float y,
            const sf::Font & font,
            std::string text
        );

        // Deconstructor
        ~Button();

        // Getters
        const bool isActive() const;
        const sf::Vector2f &getSize() const;
        const float &getWidth() const;
        const float &getHeight() const;

        // Setters
        void setText(std::string text);
        void setIsToggle();

        // Functions
        void update(const sf::Vector2f mousePos);
        void render(sf::RenderTarget &target);
    };

    class DropDownSelect
    {
    // Variables
    private:
        const sf::Font &mref_font;

        gui::Button *mptr_active;

        const sf::Color m_backgroundColor;
        sf::RectangleShape m_background;
        std::map<std::string, std::string> m_items;
        std::map<std::string, gui::Button *> m_buttons;

        float m_keytime;
        float m_keytimeMax;
        bool m_isOpen;
        std::string m_activeCode;

        const sf::Vector2f m_position;
        const sf::Vector2f m_closedSize;
        sf::Vector2f m_openSize;

    // Functions
    private:
        void initBackground();
    public:
        // Constructor
        DropDownSelect(
            const float x,
            const float y,
            const float width,
            const float height,
            const sf::Font &font
        );

        // Deconstructor
        virtual ~DropDownSelect();

        // Getters
        const std::string &getSelected() const;
        const bool getKeytime();

        // Setters
        void addAlternative(std::string key, std::string text);

        // Render functions
        void render(sf::RenderTarget &target);

        // Update function
        void updateBackgroud();
        void updateKeytime(const float &dt);
        void updateButtons(const sf::Vector2f &mouse_position);
        void updateInput(const float &dt);
        void update(const float &dt, const sf::Vector2f &mouse_position);
    };

    class ProgressBar
    {
    // Variables
    private:
        const sf::Font &mref_font;
        const float &mref_maxValue;
        const float &mref_value;
        
        sf::Vector2f m_position;
        const sf::Vector2f m_size;
        const float m_border;

        sf::RectangleShape m_background;
        sf::RectangleShape m_statusBar;

        sf::Color m_backgroundColor;
        sf::Color m_statusColor;

    // Functions
    private:
        void initBackground();
        void initStatusBar();
    public:
        // Constructors
        ProgressBar(
            const sf::Font &font,
            const float &max_value,
            const float &value,
            sf::Vector2f position,
            sf::Vector2f size,
            sf::Color color_background,
            sf::Color color_status
        );

        // Deconstructor
        ~ProgressBar();

        // Getters
        const float & getValue() const;

        // Setters

        // Update
        void update();

        // Render
        void render(sf::RenderTarget &target);

        // Function
    };
}

#endif