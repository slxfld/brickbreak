#include "Ball.hpp"
#include "Paddle.hpp"
#include "SFML/Graphics.hpp"


Ball::Ball(RessourceLoader* rl)
{
	Ball::rl = rl;
	speed = 5;
	sprite.setTexture(rl->BALL_tex);
	setDefault();
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ball::checkPaddleCollision(Paddle* paddle)
{
	// Ball intersects Paddle
	if (sprite.getGlobalBounds().intersects(paddle->sprite.getGlobalBounds()))
	{
		vx = (((sprite.getPosition().x + (sprite.getGlobalBounds().width / 2)) - (paddle->sprite.getPosition().x + paddle->sprite.getGlobalBounds().width / 2)) / 25) * (speed / 2);
		vy = (vy > 0) ? -vy : vy;
	}

	// Ball outside up
	if (sprite.getPosition().y <= 0)
		vy = (vy < 0) ? -vy : vy;

	// Ball outside left
	if (sprite.getPosition().x <= 0)
		vx = (vx < 0) ? -vx : vx;

	// Ball outside right (x + width)
	if ((sprite.getPosition().x + sprite.getGlobalBounds().width) >= 800)
		vx = (vx > 0) ? -vx : vx;
}

void Ball::update()
{
	if (iframe > 0)
		iframe--;
}

void Ball::setDefault()
{
	sprite.setPosition(400, 400);
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
	resetIframes();
}

void Ball::deflectY()
{
	vy = -vy;
	resetIframes();
}

void Ball::resetIframes()
{
	iframe = 3;
}

bool Ball::isLost()
{
	return sprite.getPosition().y > 640;
}
