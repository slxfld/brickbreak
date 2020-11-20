#include "main.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "RessourceLoader.h"

int main()
{
    Menu menu;
    RessourceLoader loader;

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