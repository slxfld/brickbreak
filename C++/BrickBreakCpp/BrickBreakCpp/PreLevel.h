
#ifndef _PRELEVEL_H_
#define _PRELEVEL_H
#include "State.h"
#pragma once
class PreLevel : public State
{
public:

	PreLevel(RessourceLoader* rl);

	void input(sf::Event& event, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update();
};

#endif
