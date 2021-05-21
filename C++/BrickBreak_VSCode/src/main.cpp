#include "main.hpp"

RessourceLoader* Access::rl = new RessourceLoader();

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "BrickBreak");
    window.setFramerateLimit(70);
    window.setVerticalSyncEnabled(true);

    Access::rl->load();

    Game game;

    sf::Sprite background;
    background.setTexture(Access::rl->BACKGROUND_tex);
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