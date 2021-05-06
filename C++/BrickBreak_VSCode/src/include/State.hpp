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

	virtual void input(sf::Event &event, sf::RenderWindow &window);
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
};
#endif

