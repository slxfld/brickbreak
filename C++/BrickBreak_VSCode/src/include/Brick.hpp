#ifndef _BRICK_H_
#define _BRICK_H_
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#pragma once
class Brick: public GameObject
{
	public:

	int value = 0;
	bool destroyed = false;
	int bAlpha = 255;

	double vy = 0;
	int falltime = 0;

	Brick();
	Brick(int value);

	void draw(sf::RenderWindow& window);
	void update();
	void destroy();
};

#endif