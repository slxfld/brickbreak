#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "SFML/Graphics.hpp"
#include "RessourceLoader.h"
#include "LevelData.h"
#pragma once
class Level
{
public:

	LevelData leveldata;

	Level();
	Level(RessourceLoader &rl);

	void input(sf::Event &event);
	void draw(sf::RenderWindow& window);
	void update();
};
#endif

