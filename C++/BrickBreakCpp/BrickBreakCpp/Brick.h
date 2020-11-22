#ifndef _BRICK_H_
#define _BRICK_H_

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RessourceLoader.h"
#pragma once
class Brick: public GameObject
{
	public:

	int value = 0;
	bool destroyed = false;

	Brick();
	Brick(int value, RessourceLoader *rl);

	void draw(sf::RenderWindow& window);
	void update();
	void destroy();
};

#endif