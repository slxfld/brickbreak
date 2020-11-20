#include "Ball.h"
#include "SFML/Graphics.hpp"
Ball::Ball()
{

}

Ball::Ball(sf::Texture texture)
{
	sprite.setTexture(texture);
}