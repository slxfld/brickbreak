
#ifndef _PRELEVEL_H_
#define _PRELEVEL_H
#include "State.hpp"
#pragma once
class PreLevel : public State
{
public:

	PreLevel();

	void input(sf::Event& event);
	void draw();
	void update();
};

#endif
