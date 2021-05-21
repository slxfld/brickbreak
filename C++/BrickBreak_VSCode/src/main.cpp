#include "main.hpp"

RessourceLoader* Access::rl = new RessourceLoader();
sf::RenderWindow* Access::window = new sf::RenderWindow(sf::VideoMode(800, 600), "BrickBreak");

int main()
{

    Access::window->setFramerateLimit(70);
    Access::window->setVerticalSyncEnabled(true);
    Access::rl->load();

    Game game;

    sf::Sprite background;
    background.setTexture(Access::rl->BACKGROUND_tex);
    background.setScale(sf::Vector2f(1.4,1.4));

    while (Access::window->isOpen())
    {
        sf::Event event;
        while (Access::window->pollEvent(event))
        {
            game.input(event);

            if (event.type == sf::Event::Closed)  Access::window->close();
        }

        Access::window->clear();
        Access::window->draw(background);
        game.update();
        game.draw();

        Access::window->display();
    }
    return 0;
}