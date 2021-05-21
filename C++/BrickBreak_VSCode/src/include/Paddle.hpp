#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "GameObject.hpp"

#pragma once
class Paddle : public GameObject
{
	public:
	bool move_left = false;
	bool move_right = false;
	Paddle();

	void input(sf::Event& event);
	void draw();
	void update();
	void setDefault();
};
#endif