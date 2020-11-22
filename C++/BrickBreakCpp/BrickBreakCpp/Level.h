#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "LevelData.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "life.h"
#pragma once
class Level : GameObject
{
	public:
	LevelData leveldata;
	Brick* bricks[10][10];
	Ball* ball;
	Paddle paddle;

	int bricksLeft = 0;
	bool running = false;
	int spawnTime = 0;

	sf::Text scoreText;
	sf::Text comboText;
	sf::Text gameoverText;

	Life *lives[3];


	Level(RessourceLoader* rl);

	void input(sf::Event& event, sf::RenderWindow &window);
	void draw(sf::RenderWindow& window);
	void update();

	void collisions();
	void next();
	void start();
	void restart();
	void construct(int index);
	void begin();
	void lostLife();
	bool checkWin();
};
#endif

