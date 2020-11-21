#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "LevelData.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"

#pragma once
class Level : GameObject
{
	public:
	LevelData leveldata;
	Brick* bricks[10][10];
	Ball* ball;
	Paddle paddle;

	bool gameover = false;
	bool running = false;
	int timeleft = 0;

	Level(RessourceLoader* rl);

	void input(sf::Event& event);
	void draw(sf::RenderWindow& window);
	void update();

	void collisions();
	void start();
	void construct(int index);
	void begin();
};
#endif

