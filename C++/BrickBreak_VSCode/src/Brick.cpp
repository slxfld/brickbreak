#include "Brick.hpp"

Brick::Brick()
{
	
}

Brick::Brick(int value)
{
	switch (value)
	{
		case 0: sprite.setTexture(Access::rl->BRICK_1_GR1_tex);	Brick::value = 0; break;
		case 1: sprite.setTexture(Access::rl->BRICK_1_B1_tex);	Brick::value = 100; break;
		case 2: sprite.setTexture(Access::rl->BRICK_1_G1_tex);	Brick::value = 200; break;
		case 3: sprite.setTexture(Access::rl->BRICK_1_R1_tex);	Brick::value = 300; break;
		case 4: sprite.setTexture(Access::rl->BRICK_1_V1_tex);	Brick::value = 400; break;
		case 5: sprite.setTexture(Access::rl->BRICK_1_Y1_tex);	Brick::value = 500; break;
		case 6: sprite.setTexture(Access::rl->BRICK_1_O1_tex);	Brick::value = 600; break;
	}

	sprite.setScale(1,1.17);
	sprite.setPosition(-500, -500);
}

void Brick::update()
{
	if (falltime > 0)
	{
		falltime--;
		sprite.move(sf::Vector2f(0,vy));
		sprite.rotate(5);
		sprite.setColor(sf::Color(255,255,255,bAlpha));
		bAlpha = (bAlpha > 0) ? bAlpha - 5 : bAlpha;
		vy++;
	}
}

void Brick::draw()
{
	Access::window->draw(sprite);
}

void Brick::destroy()
{
	falltime = 120;
	vy = -10;
	destroyed = true;
}