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

	pausedText.setFont(rl->font);
	pausedText.setPosition(sf::Vector2f(300,300));
	pausedText.setString("Game Paused");
}


void Level::input(sf::Event& event, sf::RenderWindow &window)
{
	if (selectingSpeed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (!KEY_LEFT)
			{
				KEY_LEFT = true;
				ball->speed--;
			}
		}
		else
		{
			KEY_LEFT = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (!KEY_RIGHT)
			{
				KEY_RIGHT = true;
				ball->speed++;
			}
		}
		else
		{
			KEY_RIGHT = false;
		}

		speedText.setString("Select Speed\n" + std::to_string(ball->speed));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			selectingSpeed = false;
			begin();
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			leveldata.setDefault();
			leveldata.gameover = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			if (!KEY_P)
			{
				KEY_P = true;
				isPaused = (isPaused) ? false : true;
				if(LOGGING_ENABLED) std::cout << "paused: " << isPaused << "\n";
			}
		}
		else
		{
			KEY_P = false;
		}

		if (!isRunning)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				isRunning = true;
			}
		}

		if (event.type == sf::Event::MouseMoved)
		{
			double window_width = window.getSize().x;
			double mouseX = ((double)sf::Mouse::getPosition(window).x / (double)window_width) * 800;

			paddle->sprite.setPosition(mouseX - (paddle->sprite.getGlobalBounds().width / 2), 500);
		}
	}
}

void Level::draw(sf::RenderWindow& window)
{
	if (selectingSpeed == false)
	{
		for (auto i : gameobjects)
			i->draw(window);
		combo->draw(window);

		if (isPaused)
		{
			window.draw(pausedText);
		}
	}
	window.draw(scoreText);
	window.draw(gameoverText);
	window.draw(speedText);
}

void Level::update()
{
	if (isRunning)
	{
		if (!isPaused)
		{
			for (auto i : gameobjects) {
				i->update();
				if (i->delete_me)
				{
					gameobjects.remove(i);
					delete(i);
				}
			}

			collisions();

			if (checkWin()) { nextLevel(); }
		}
	}
	else
	{
		if (ball->onPaddle)
		{
			ball->sprite.setPosition(paddle->sprite.getPosition() + sf::Vector2f(paddle->sprite.getGlobalBounds().width/2, -20));
		}
	}
}

void Level::collisions()
{
	ball->checkPaddleCollision(paddle);

	if (ball->isLost()) { loseLife(); }

	ball->sprite.move(ball->vx, 0);
	if (checkBallBrickCollision()) { ball->deflectX(); }

	ball->sprite.move(0, ball->vy);
	if (checkBallBrickCollision()) { ball->deflectY(); }
}

bool Level::checkBallBrickCollision()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
			{
				if (ball->iframe == 0 && !bricks[i][j]->destroyed)
				{
					if (LOGGING_ENABLED) std::cout << "Destroy Brick <" << j << "," << i << ">\n";

					combo->addCombo(bricks[i][j]->value);
					addScore(bricks[i][j]->value);
					scoreText.setString("Score: " + std::to_string(leveldata.score));
					gameobjects.push_back(new FadingScore(bricks[i][j]->sprite.getPosition(),(bricks[i][j]->value * combo->combo),rl));
					bricksLeft--;
					bricks[i][j]->destroy();


					return true;
				}
			}
		}
	}
	return false;
}
bool Level::checkWin()
{
	return (bricksLeft == 0);
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
		for (int j = 0; j < 8; j++)
		{
			if(LOGGING_ENABLED) std::cout << "level = " << index << "\n";
			if(LOGGING_ENABLED) std::cout << "create brick type " << leveldata.levelLayout[index][i][j] << " \n";
			bricks[i][j] = new Brick(leveldata.levelLayout[index][i][j], rl);
			
			if (bricks[i][j]->value != 0)
			{
				bricks[i][j]->sprite.setPosition(sf::Vector2f(60 + (j * 85), 20 + (i * 32)));
				bricksLeft++;
				gameobjects.push_back(bricks[i][j]);
			}
		}
	}
}

void Level::begin()
{
	leveldata.setDefault();
	for (int i = 0; i < 3; i++) lives[i]->alive = true;

	gameoverText.setString("");
	speedText.setPosition(sf::Vector2f(-500, -500));
	nextLevel();
	restartLevel();
}

void Level::restartLevel()
{
	isRunning = false;
	spawnTimer = 90;
	if(LOGGING_ENABLED) std::cout << "time set to " << spawnTimer << "\n";

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

void Level::createLives()
{
	for (int i = 0; i < 3; i++)
	{
		lives[i] = new Life(rl);
		lives[i]->sprite.setPosition(sf::Vector2f(650 + (i * 30), 30));
	}
}


