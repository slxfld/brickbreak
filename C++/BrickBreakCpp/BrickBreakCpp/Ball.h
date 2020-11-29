#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.h"
#include "Paddle.h"

#pragma once
class Ball : public GameObject
{

	public:
	double vx = 0;
	double vy = 0;
	double speed = 0;
	bool active = false;
	int iframe = 0;

	Ball(RessourceLoader* rl);

	void update();
	void draw(sf::RenderWindow &window);

	void setDefault();
	void calculateVX(sf::Vector2f v1, sf::Vector2f v2);
	void checkPaddleCollision(Paddle* paddle);
	void deflectY();
	void deflectX();
	void resetIframes();
};
#endif