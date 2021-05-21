#include "Life.hpp"

Life::Life()
{
	sprite.setTexture(Access::rl->LIFE_tex);
}

void Life::update()
{

}

void Life::draw(sf::RenderWindow& window)
{
	if(alive) window.draw(sprite);
}