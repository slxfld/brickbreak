#ifndef _PICKUP_H_
#define _PICKUP_H_
#include "GameObject.hpp"
#pragma once
class Pickup : public GameObject
{
public:

	bool isUsed = false;
	int despawnCounter = 0;
	Pickup();

	void draw(sf::RenderWindow& window);
	void update();
};

#endif