#include "Ball.h"
#include "SFML/Graphics.hpp"

Ball::Ball()
{

}

Ball::Ball(RessourceLoader* rl)
{
	Ball::rl = rl;
	sprite.setTexture(rl->BALL_tex);
	setDefault();
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ball::update()
{
	sprite.move(vx, vy);
}

void Ball::setDefault()
{
	vx = 2;
	vy = -2;
}