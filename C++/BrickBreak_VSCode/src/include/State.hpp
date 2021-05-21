#ifndef _STATE_H_
#define _STATE_H_
#include "SFML/Graphics.hpp"
#pragma once
class State
{
public:
	State();

	bool LOGGING_ENABLED = false;

	bool KEY_LEFT = false;
	bool KEY_RIGHT = false;
	bool KEY_UP = false;
	bool KEY_DOWN = false;

	bool KEY_P = false;

	virtual void input(sf::Event &event);
	virtual void update();
	virtual void draw();
};
#endif

