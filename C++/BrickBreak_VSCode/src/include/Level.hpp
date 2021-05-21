#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "State.hpp"
#include "LevelData.hpp"
#include "Brick.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "life.hpp"
#include "Combo.hpp"
#include "FadingScore.hpp"
#include "Access.hpp"
#include <list>
#pragma once
class Level : public State
{
	public:
	LevelData leveldata;
	Brick bricks[10][10];
	Ball ball;
	Paddle paddle;
	Combo combo;
	std::list<GameObject*> gameobjects;

	int bricksLeft = 0;
	bool isRunning = false;
	bool isPaused = false;
	bool selectingSpeed = false;
	int spawnTimer = 0;

	sf::Text scoreText;
	sf::Text gameoverText;
	sf::Text speedText;
	sf::Text pausedText;

	sf::RectangleShape comboBar;

	Life lives[3];

	Level();

	void input(sf::Event& event, sf::RenderWindow &window);
	void draw(sf::RenderWindow& window);
	void update();

	void collisions();
	bool checkBallBrickCollision();	// no
	void addScore(int value);	//no
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

