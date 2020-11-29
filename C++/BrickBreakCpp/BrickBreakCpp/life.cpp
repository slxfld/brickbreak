#include "life.h"

Life::Life(RessourceLoader *rl)
{
	sprite.setTexture(rl->LIFE_tex);
}

void Life::update()
{

}

void Life::draw(sf::RenderWindow& window)
{
	if(alive) window.draw(sprite);
}