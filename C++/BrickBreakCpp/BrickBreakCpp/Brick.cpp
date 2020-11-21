#include "Brick.h"
Brick::Brick()
{

}

Brick::Brick(int value, RessourceLoader *rl)
{
	switch (value)
	{
		case 0: sprite.setTexture(rl->BRICK_1_GR1_tex);	break;
		case 1: sprite.setTexture(rl->BRICK_1_G1_tex);	break;
		case 2: sprite.setTexture(rl->BRICK_1_B1_tex);	break;
		case 3: sprite.setTexture(rl->BRICK_1_O1_tex);	break;
		case 4: sprite.setTexture(rl->BRICK_1_R1_tex);	break;
		case 5: sprite.setTexture(rl->BRICK_1_V1_tex);	break;
		case 6: sprite.setTexture(rl->BRICK_1_Y1_tex);	break;
		case 7: sprite.setTexture(rl->BRICK_1_GR1_tex); break;
	}
	sprite.setScale(1.1,1.17);
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}