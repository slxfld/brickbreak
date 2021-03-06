#include "Paddle.hpp"

Paddle::Paddle()
{
	sprite.setTexture(Access::rl->PAD_tex);
	sprite.setScale(sf::Vector2f(1,1.14));
	sprite.setPosition(sf::Vector2f(-40 + 640 / 2, 640 - 50));
	setDefault();
}

void Paddle::setDefault()
{
	sprite.setPosition(sf::Vector2f(400, 500));
}

void Paddle::update()
{
	if (move_right)
		sprite.move(5, 0);
	if (move_left)
		sprite.move(-5, 0);
}

void Paddle::input(sf::Event& event)
{
}

void Paddle::draw()
{
	Access::window->draw(sprite);
}
