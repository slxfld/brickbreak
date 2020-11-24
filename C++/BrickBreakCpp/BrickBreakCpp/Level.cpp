#include "Level.h"
#include <string>

Level::Level(RessourceLoader* rl) : paddle(rl), comboBar(sf::Vector2f(10,10))
{
	Level::rl = rl;
	std::cout << "<Level> create\n";
	for (int i = 0; i < 3; i++)
		lives[i] = new Life(rl);

	lives[0]->sprite.setPosition(sf::Vector2f(650, 30));
	lives[1]->sprite.setPosition(sf::Vector2f(680, 30));
	lives[2]->sprite.setPosition(sf::Vector2f(710, 30));

	gameoverText.setFont(rl->font);
	gameoverText.setPosition(sf::Vector2f(270,320));

	scoreText.setFont(rl->font);
	scoreText.setScale(sf::Vector2f(0.7, 0.7));
	scoreText.setPosition(sf::Vector2f(20,20));

	comboText.setFont(rl->font);
	comboText.setScale(sf::Vector2f(0.7,0.7));
	comboText.setPosition(sf::Vector2f(20,50));

	speedText.setFont(rl->font);
	speedText.setScale(sf::Vector2f(0.8,0.8));

	comboBar.setPosition(sf::Vector2f(5, 80));
	comboBar.setFillColor(sf::Color::Green);
}


void Level::input(sf::Event& event, sf::RenderWindow &window)
{
	if (selectSpeed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == 1)
		{
			leveldata.speed-=0.1;
			speedText.setString("Select Speed: " + std::to_string(leveldata.speed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == 1)
		{
			leveldata.speed+=0.1;
			speedText.setString("Select Speed: " + std::to_string(leveldata.speed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			selectSpeed = false;
			speedText.setPosition(sf::Vector2f(-500, -500));
			begin();
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			paddle.move_left = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			paddle.move_right = true;

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			paddle.move_left = false;
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			paddle.move_right = false;

		if (event.type == sf::Event::MouseMoved)
			paddle.sprite.setPosition(sf::Mouse::getPosition(window).x - (paddle.sprite.getGlobalBounds().width / 2), 500);
	}
}

void Level::draw(sf::RenderWindow& window)
{


	if (running)
	{ 
		paddle.draw(window);
		ball->draw(window);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				bricks[i][j]->draw(window);
	}
	for (int i = 0; i < leveldata.lives; i++)
		lives[i]->draw(window);

	window.draw(scoreText);
	window.draw(gameoverText);
	window.draw(speedText);

	if (comboTime > 0)
	{
		comboText.setScale(sf::Vector2f(0.7 + (comboSize),0.7 + (comboSize)));
		window.draw(comboText);
		window.draw(comboBar);
	}
}


void Level::start()
{
	running = true;
}

void Level::construct(int index)
{
	bricksLeft = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
		{
			std::cout << "level = " << index << "\n";
			std::cout << "create brick type " << leveldata.levelLayout[index][i][j] << " \n";
			bricks[i][j] = new Brick(leveldata.levelLayout[index][i][j], rl);
			if (bricks[i][j]->value != 0)
			{
				bricks[i][j]->sprite.setPosition(sf::Vector2f(70 + (j * 93), 20 + (i * 35)));
				bricksLeft++;
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
	ball = new Ball(rl, leveldata.speed);
	construct(leveldata.currentLevel);
	restart();
}

void Level::restart()
{
	running = false;
	spawnTime = 90;
	std::cout << "time set to " << spawnTime << "\n";
	paddle.setDefault();
	ball->setDefault(leveldata.speed);
}

void Level::lostLife()
{
	leveldata.lives--;
	if (leveldata.lives == 0)
		leveldata.gameover = true;
	else
		restart();
}

void Level::next()
{
	leveldata.currentLevel++;
	if (leveldata.currentLevel == 9)
	{
		gameoverText.setString("All Levels complete!\n Your Score is: " + std::to_string(leveldata.score));
	}
	else
	{
	construct(leveldata.currentLevel);
	restart();
	}
}

void Level::addScore(int value)
{
	leveldata.score += (value * leveldata.combo);
}

void Level::update()
{
	if (spawnTime > 0)
	{
		spawnTime--;
		if (spawnTime <= 0)
		{
			start();
		}
	}

	if (running)
	{
		paddle.update();

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				bricks[i][j]->update();


		comboText.setString("Combo: " + std::to_string((int)leveldata.combo) + "x");


		int comboBarSize = (   (comboTime) / ((200 + comboExtraTime))  ) * 100;
		comboBar.setSize(sf::Vector2f(comboBarSize,10));

		// Ball intersects Brick after moving X
		ball->sprite.move(ball->vx, 0);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
					if (ball->iframe == 0 && !bricks[i][j]->destroyed)
					{
						std::cout << "Destroy Brick <" << j << "," << i << ">\n";
						leveldata.combo += bricks[i][j]->value/100;
						comboTime = 200 + comboExtraTime;
						comboSize = 0.3;
						if (comboExtraTime < 200)
							comboExtraTime += 10;

						addScore(bricks[i][j]->value);
						scoreText.setString("Score: " + std::to_string(leveldata.score));

						bricksLeft--;
						bricks[i][j]->destroy();
						ball->deflectX();
					}

		// Ball intersects Brick after moving Y
		ball->sprite.move(0, ball->vy);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
					if (ball->iframe == 0 && !bricks[i][j]->destroyed)
					{
						std::cout << "Destroy Brick <" << j << "," << i << ">\n";
						leveldata.combo += bricks[i][j]->value / 100;
						comboTime = 200 + comboExtraTime;
						comboSize = 0.3;
						if (comboExtraTime < 200)
							comboExtraTime += 10;

						addScore(bricks[i][j]->value);
						scoreText.setString("Score: " + std::to_string(leveldata.score));

						bricksLeft--;
						bricks[i][j]->destroy();
						ball->deflectY();
					}

		// Check Win
		if (checkWin())
			next();

		// Ball intersects Paddle
		if (ball->sprite.getGlobalBounds().intersects(paddle.sprite.getGlobalBounds()))
		{
			ball->vx = (((ball->sprite.getPosition().x + (ball->sprite.getGlobalBounds().width/2)) - (paddle.sprite.getPosition().x + paddle.sprite.getGlobalBounds().width / 2)) / 25) * (ball->speed/2);
			ball->vy = (ball->vy > 0) ? -ball->vy : ball->vy;
		}

		// Ball outside up
		if (ball->sprite.getPosition().y <= 0)
			ball->vy = (ball->vy < 0) ? -ball->vy : ball->vy;

		// Ball outside left
		if (ball->sprite.getPosition().x <= 0)
			ball->vx = (ball->vx < 0) ? -ball->vx : ball->vx;

		// Ball outside right (x + width)
		if ((ball->sprite.getPosition().x + ball->sprite.getGlobalBounds().width) >= 800)
			ball->vx = (ball->vx > 0) ? -ball->vx : ball->vx;

		// Ball left screen low
		if (ball->sprite.getPosition().y > 640)
			lostLife();

		if (ball->iframe > 0)
			ball->iframe--;

		if (comboTime > 0)
		{
			comboTime--;

			if (comboSize > 0)
				comboSize-=0.025;

			if (comboTime == 0)
			{
				comboExtraTime = 0;
				leveldata.combo = 0;
			}
				
		}
	}
}

void Level::createLives()
{
}


