#include "Life.hpp"

Life::Life()
{
	sprite.setTexture(Access::rl->LIFE_tex);
}

void Life::update()
{

}

void Life::draw()
{
	if(alive) Access::window->draw(sprite);
}