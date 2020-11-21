#include "Ball.h"
#include "SFML/Graphics.hpp"
Ball::Ball()
{

}

Ball::Ball(RessourceLoader &rl)
{
	sprite.setTexture(rl.BALL_tex);
}