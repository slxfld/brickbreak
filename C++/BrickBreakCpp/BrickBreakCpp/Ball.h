#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.h"

#pragma once
class Ball : public GameObject
{
	public:
	int vx;
	int vy;

	Ball();
	Ball(RessourceLoader* rl);

	void update();
	void draw(sf::RenderWindow &window);

	void setDefault();
};
#endif