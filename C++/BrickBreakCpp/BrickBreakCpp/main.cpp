#include "main.h"
#include "Menu.h"
#include "RessourceLoader.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Level.h"

enum GAME_STATE
{
    MAIN_MENU,
    LEVEL,
    HIGHSCORES,
    OPTIONS
};


int main()
{
    RessourceLoader loader;
    loader.load();

    GAME_STATE state = MAIN_MENU;

    Menu menu(&loader);
    Level level(&loader);

    sf::RenderWindow window(sf::VideoMode(800, 640), "Breakout 70");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

        // Input
        switch (state)
        {
            case MAIN_MENU:menu.input(event); break;
            case LEVEL: level.input(event); break;
        }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update
        switch (state)
        {
            case MAIN_MENU:menu.update(); break;
            case LEVEL: level.update(); break;
        }

        window.clear();
        // Render
        switch (state)
        {
            case MAIN_MENU: menu.draw(window); break;
            case LEVEL: level.draw(window); break;
        }

        window.display();
    }

    return 0;
}