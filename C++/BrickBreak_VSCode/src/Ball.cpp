#include "Ball.hpp"
#include "Paddle.hpp"
#include "SFML/Graphics.hpp"

Ball::Ball()
{
	std::cout << "ball constructor called!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	speed = 5;
	sprite.setTexture(Access::rl->BALL_tex);
	sound.setBuffer(Access::rl->BALL_SND);
	setDefault();
}

void Ball::draw()
{
	Access::window->draw(sprite);
}

void Ball::checkPaddleCollision(Paddle &paddle)
{
	// Ball intersects Paddle
	if (sprite.getGlobalBounds().intersects(paddle.sprite.getGlobalBounds()))
	{
		vx = (((sprite.getPosition().x + (sprite.getGlobalBounds().width / 2)) - (paddle.sprite.getPosition().x + paddle.sprite.getGlobalBounds().width / 2)) / 25) * (speed / 2);
		vy = (vy > 0) ? -vy : vy;
		sound.play();
	}

	// Ball outside up
	if (sprite.getPosition().y <= 0)
		vy = (vy < 0) ? -vy : vy;
	
	// Ball outside left
	if (sprite.getPosition().x <= 50)
		vx = (vx < 0) ? -vx : vx;
	
	// Ball outside right (x + width)
	if ((sprite.getPosition().x + sprite.getGlobalBounds().width) >= (800-50))
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
	onPaddle = true;
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
	sound.play();
}

void Ball::deflectY()
{
	vy = -vy;
	resetIframes();
	sound.play();
}

void Ball::resetIframes()
{
	iframe = 3;
}

bool Ball::isLost()
{
	return sprite.getPosition().y > 640;
}
