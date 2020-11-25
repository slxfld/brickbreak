#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "GameObject.h"

#pragma once
class Paddle : public GameObject
{
	public:
	bool move_left = false;
	bool move_right = false;
	Paddle(RessourceLoader *rl);

	void input(sf::Event& event);
	void draw(sf::RenderWindow &window);
	void update();
	void setDefault();
};
#endif