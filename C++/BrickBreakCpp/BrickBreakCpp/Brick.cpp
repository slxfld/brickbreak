#include "Brick.h"

Brick::Brick(int value, RessourceLoader *rl)
{
	switch (value)
	{
		case 0: sprite.setTexture(rl->BRICK_1_GR1_tex);	Brick::value = 0; break;
		case 1: sprite.setTexture(rl->BRICK_1_B1_tex);	Brick::value = 100; break;
		case 2: sprite.setTexture(rl->BRICK_1_G1_tex);	Brick::value = 200; break;
		case 3: sprite.setTexture(rl->BRICK_1_R1_tex);	Brick::value = 300; break;
		case 4: sprite.setTexture(rl->BRICK_1_V1_tex);	Brick::value = 400; break;
		case 5: sprite.setTexture(rl->BRICK_1_Y1_tex);	Brick::value = 500; break;
		case 6: sprite.setTexture(rl->BRICK_1_GR1_tex);	Brick::value = 600; break;
	}
	sprite.setScale(1.1,1.17);
	sprite.setPosition(-500, -500);
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Brick::destroy()
{
	sprite.setPosition(-100, -100);
	destroyed = true;
}