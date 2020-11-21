#include "Ball.h"
#include "SFML/Graphics.hpp"


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

}

void Ball::setDefault()
{
	vx = 2;
	vy = -2;
}

void Ball::calculateVX(sf::Vector2f v1, sf::Vector2f v2)
{
	vx = ((v1.x - v2.x)) / 10;

}