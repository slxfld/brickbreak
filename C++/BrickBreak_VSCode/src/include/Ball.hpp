#ifndef _BALL_H_
#define _BALL_H_

#include "GameObject.hpp"
#include "Paddle.hpp"

#pragma once
class Ball : public GameObject
{
	public:
	double vx = 0;
	double vy = 0;
	int speed = 0;
	bool active = false;
	bool onPaddle = false;
	int iframe = 0;

	Ball();

	void update();
	void draw(sf::RenderWindow &window);

	void setDefault();
	void calculateVX(sf::Vector2f v1, sf::Vector2f v2);
	void checkPaddleCollision(Paddle &paddle);
	void deflectY();
	void deflectX();
	void resetIframes();
	bool isLost();
};
#endif