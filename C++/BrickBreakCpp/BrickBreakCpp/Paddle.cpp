#include "Paddle.h"

Paddle::Paddle(RessourceLoader* rl)
{
	sprite.setTexture(rl->PAD_tex);
	sprite.setScale(sf::Vector2f(1,1.14));
	sprite.setPosition(sf::Vector2f(-40 + 640 / 2, 640 - 50));
	setDefault();
}

void Paddle::setDefault()
{

}

void Paddle::update()
{

}

void Paddle::draw()
{

}