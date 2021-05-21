
#ifndef _PRELEVEL_H_
#define _PRELEVEL_H
#include "State.hpp"
#pragma once
class PreLevel : public State
{
public:

	PreLevel();

	void input(sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update();
};

#endif
