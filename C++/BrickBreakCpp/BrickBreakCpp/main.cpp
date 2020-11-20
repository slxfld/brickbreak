#include "main.h"
#include "Menu.h"
#include "RessourceLoader.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

enum GAME_STATE
{
    MAIN_MENU,
    LEVEL,
    HIGHSCORES,
    OPTIONS
};


int main()
{
    Menu menu;
    RessourceLoader loader;

    GAME_STATE state = GAME_STATE::MAIN_MENU;

    sf::RenderWindow window(sf::VideoMode(800, 640), "Breakout 70");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.display();
    }

    return 0;
}