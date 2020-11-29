#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "State.h"
#include "LevelData.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "life.h"
#include "Combo.h"
#include <list>
#pragma once
class Level : public State
{
	public:
	LevelData leveldata;
	Brick* bricks[10][10];
	Ball* ball;
	Paddle *paddle;
	Combo *combo;
	std::list<GameObject*> gameobjects;

	int bricksLeft = 0;
	bool isRunning = false;
	bool selectSpeed = false;
	int spawnTime = 0;

	sf::Text scoreText;
	sf::Text gameoverText;
	sf::Text speedText;

	sf::RectangleShape comboBar;

	Life *lives[3];

	Level(RessourceLoader* rl);

	void input(sf::Event& event, sf::RenderWindow &window);
	void draw(sf::RenderWindow& window);
	void update();

	bool ballCollision();
	void addScore(int value);
	void restartLevel();

	void construct(int index);
	void createLives();

	void begin();
	void start();
	void nextLevel();
	bool checkWin();
	void loseLife();
};
#endif

