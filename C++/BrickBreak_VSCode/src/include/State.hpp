#ifndef _STATE_H_
#define _STATE_H_
#include "SFML/Graphics.hpp"
#include "RessourceLoader.hpp"
#pragma once
class State
{
public:
	RessourceLoader* rl;

	State();

	bool LOGGING_ENABLED = false;

	bool KEY_LEFT = false;
	bool KEY_RIGHT = false;
	bool KEY_UP = false;
	bool KEY_DOWN = false;

	bool KEY_P = false;

	virtual void input(sf::Event &event, sf::RenderWindow &window);
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
};
#endif

