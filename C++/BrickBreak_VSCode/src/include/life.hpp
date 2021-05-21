#ifndef _LIFE_H_
#define _LIFE_H_
#include "GameObject.hpp"
#pragma once
class Life : public GameObject
{
public:

	bool alive = true;
	Life();

	void draw(sf::RenderWindow& window);
	void update();
};

#endif