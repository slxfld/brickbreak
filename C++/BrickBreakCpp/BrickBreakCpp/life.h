#ifndef _LIFE_H_
#define _LIFE_H_
#include "GameObject.h"
#pragma once
class Life : public GameObject
{
public:
	Life(RessourceLoader *rl);

	void draw(sf::RenderWindow& window);
	void update();
};

#endif