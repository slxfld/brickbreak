#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "LevelData.h"
#include "Brick.h"
#include "Ball.h"

#pragma once
class Level : GameObject
{
	public:
	LevelData leveldata;
	Brick bricks[7][10];
	Ball ball;

	Level();
	Level(RessourceLoader* rl);

	void input(sf::Event& event);
	void draw(sf::RenderWindow& window);
	void update();
	void collisions();
};
#endif

