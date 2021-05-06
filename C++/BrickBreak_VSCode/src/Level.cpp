#include "Level.hpp"
#include <string>

Level::Level(RessourceLoader* rl)
{
	std::cout << "<Level> created\n";
	Level::rl = rl;

	ball = new Ball(rl);
	paddle = new Paddle(rl);
	combo = new Combo(rl);

	createLives();

	gameoverText.setFont(rl->font);
	gameoverText.setPosition(sf::Vector2f(270,320));

	scoreText.setFont(rl->font);
	scoreText.setScale(sf::Vector2f(0.7, 0.7));
	scoreText.setPosition(sf::Vector2f(20,20));

	speedText.setFont(rl->font);
	speedText.setScale(sf::Vector2f(0.8,0.8));
}

void Level::input(sf::Event& event, sf::RenderWindow &window)
{
	if (selectSpeed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { ball->speed -= 0.1; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { ball->speed += 0.1; }

		speedText.setString("Select Speed: " + std::to_string(ball->speed));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { selectSpeed = false; begin(); }
	}
	else
	{
		paddle->move_left = (sf::Keyboard::isKeyPressed(sf::Keyboard::A));
		paddle->move_right = (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			leveldata.gameover = true;
		}
		
		if (event.type == sf::Event::MouseMoved)
		{
			paddle->sprite.setPosition(sf::Mouse::getPosition(window).x -
				(paddle->sprite.getGlobalBounds().width / 2), 500);
		}
	}
}

void Level::draw(sf::RenderWindow& window)
{
	if (selectSpeed == false)
		for (auto i : gameobjects)
			i->draw(window);


	window.draw(scoreText);
	window.draw(gameoverText);
	window.draw(speedText);
	combo->draw(window);
}

void Level::start()
{
	isRunning = true;
}

void Level::construct(int index)
{
	bricksLeft = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::cout << "level = " << index << "\n";
			std::cout << "create brick type " << leveldata.levelLayout[index][i][j] << " \n";
			bricks[i][j] = new Brick(leveldata.levelLayout[index][i][j], rl);
			
			if (bricks[i][j]->value != 0)
			{
				bricks[i][j]->sprite.setPosition(sf::Vector2f(70 + (j * 93), 20 + (i * 35)));
				bricksLeft++;
				gameobjects.push_back(bricks[i][j]);
			}
		}
	}
}

bool Level::checkWin()
{
	if (bricksLeft == 0)
		return true;
	return false;
}

void Level::begin()
{
	leveldata.setDefault();
	for (int i = 0; i < 3; i++) lives[i]->alive = true;

	speedText.setPosition(sf::Vector2f(-500, -500));
	nextLevel();
	restartLevel();
}

void Level::restartLevel()
{
	isRunning = false;
	spawnTime = 90;
	std::cout << "time set to " << spawnTime << "\n";

	paddle->setDefault();
	ball->setDefault();
}

void Level::loseLife()
{
	leveldata.lives--;
	lives[leveldata.lives]->alive = false;
	if (leveldata.lives == 0)
		leveldata.gameover = true;
	else
		restartLevel();
}

void Level::nextLevel()
{
	leveldata.currentLevel++;
	if (leveldata.currentLevel == 9)
	{
		gameoverText.setString("All Levels complete!\n Your Score is: " + std::to_string(leveldata.score));
		isRunning = false;
	}
	else
	{
		gameobjects.clear();
		construct(leveldata.currentLevel);
		gameobjects.push_back(ball);
		gameobjects.push_back(paddle);
		gameobjects.push_back(combo);
		for (int i = 0; i < 3; i++)
			gameobjects.push_back(lives[i]);

		restartLevel();
	}
}

void Level::addScore(int value)
{
	leveldata.score += (value * combo->combo);
}

void Level::update()
{
	if (spawnTime > 0)
	{
		spawnTime--;
		if (spawnTime <= 0) { start(); }
	}

	if (isRunning)
	{
		for (auto i : gameobjects)
			i->update();

		ball->checkPaddleCollision(paddle);

		if (ball->isLost()) { loseLife(); }

		ball->sprite.move(ball->vx, 0);
		if (ballCollision()) { ball->deflectX(); }

		ball->sprite.move(0, ball->vy);
		if (ballCollision()) { ball->deflectY(); }

		if (checkWin()) { nextLevel(); }
	}
}

bool Level::ballCollision()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
			{
				if (ball->iframe == 0 && !bricks[i][j]->destroyed)
				{
					std::cout << "Destroy Brick <" << j << "," << i << ">\n";

					combo->addCombo(bricks[i][j]->value);
					addScore(bricks[i][j]->value);
					scoreText.setString("Score: " + std::to_string(leveldata.score));

					bricksLeft--;
					bricks[i][j]->destroy();
					return true;
				}
			}
		}
	}
	return false;
}

void Level::createLives()
{
	for (int i = 0; i < 3; i++)
	{
		lives[i] = new Life(rl);
		lives[i]->sprite.setPosition(sf::Vector2f(650 + (i * 30), 30));
	}
}

