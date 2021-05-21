#include "main.hpp"
#include "Menu.hpp"
#include "RessourceLoader.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Level.hpp"
#include "Game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "BrickBreak");
    window.setFramerateLimit(70);
    window.setVerticalSyncEnabled(true);

    RessourceLoader loader;
    loader.load();

    Game game(&loader);

    sf::Sprite background;
    background.setTexture(loader.BACKGROUND_tex);
    background.setScale(sf::Vector2f(1.4,1.4));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            game.input(event, window);

            if (event.type == sf::Event::Closed)    window.close();
        }

        window.clear();

        window.draw(background);
        game.update();
        game.draw(window);

        window.display();
    }
    return 0;
}