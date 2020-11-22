#include "Ball.h"
#include "SFML/Graphics.hpp"


Ball::Ball(RessourceLoader* rl, int speed)
{
	Ball::rl = rl;
	sprite.setTexture(rl->BALL_tex);
	setDefault(speed);
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ball::update()
{

}

void Ball::setDefault(int speed)
{
	Ball::speed = speed;
	sprite.setPosition(320, 400);
	active = false;
	vx = -2;
	vy = -speed;
}

void Ball::calculateVX(sf::Vector2f v1, sf::Vector2f v2)
{
	vx = (((v1.x - v2.x)) / 10);
}

void Ball::deflectX()
{
	vx = -vx;
	iframe = 2;
}

void Ball::deflectY()
{
	vy = -vy;
	iframe = 2;
}