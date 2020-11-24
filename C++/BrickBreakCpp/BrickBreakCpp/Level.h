#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "State.h"
#include "LevelData.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "life.h"
#pragma once
class Level : public State
{
	public:
	LevelData leveldata;
	Brick* bricks[10][10];
	Ball* ball;
	Paddle paddle;

	int bricksLeft = 0;
	bool running = false;
	bool selectSpeed = false;
	int spawnTime = 0;

	double comboTime = 100;
	double comboExtraTime = 0;
	double comboSize = 0;
	int combo = 0;
	int combo_R = 0;
	int combo_G = 0;
	int combo_B = 0;

	sf::Text scoreText;
	sf::Text comboText;
	sf::Text gameoverText;
	sf::Text speedText;



	sf::RectangleShape comboBar;

	Life *lives[3];

	Level(RessourceLoader* rl);

	void input(sf::Event& event, sf::RenderWindow &window);
	void draw(sf::RenderWindow& window);
	void update();

	void collisions();
	void next();
	void addScore(int value);
	void start();
	void restart();
	void construct(int index);
	void begin();
	void lostLife();
	bool checkWin();
};
#endif

