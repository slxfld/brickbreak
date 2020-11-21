#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.h"

#pragma once
class Ball : public GameObject
{

	public:
	double vx = 0;
	double vy = 0;
	bool active = false;

	Ball(RessourceLoader* rl);

	void update();
	void draw(sf::RenderWindow &window);

	void setDefault();
	void calculateVX(sf::Vector2f v1, sf::Vector2f v2);
};
#endif