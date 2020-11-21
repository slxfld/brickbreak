#include "Level.h"

Level::Level(RessourceLoader* rl) : paddle(rl)
{
	Level::rl = rl;
	std::cout << "<Level> create\n";
}

void Level::input(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		paddle.move_left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		paddle.move_right = true;

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		paddle.move_left = false;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		paddle.move_right = false;

}

void Level::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			bricks[i][j]->draw(window);

	if (running)
	{ 
		paddle.draw(window);
		ball->draw(window);
	}
}

void Level::collisions()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
			{
				std::cout << "Ball intersected Brick <" << j << "," << i << ">\n";
			}
}

void Level::start()
{
	ball = new Ball(rl);
	ball->sprite.setPosition(sf::Vector2f(320, 420));
	ball->active = true;
	running = true;
}

void Level::construct(int index)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
		{
			bricks[i][j] = new Brick(leveldata.levelLayout[i][j][index], rl);
			bricks[i][j]->sprite.setPosition(sf::Vector2f(20+(j*93),20+(i*35)));
		}
	spawnTime = 90;
	std::cout << "time set to " << spawnTime << "\n";
}

void Level::begin()
{
	leveldata.setDefault();
	construct(0);
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

		// Ball intersects Brick after moving X
		ball->sprite.move(ball->vx, 0);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
				{
					std::cout << "Ball intersected Brick <" << j << "," << i << ">\n";
					bricks[i][j]->sprite.setPosition(sf::Vector2f(-20,-20));
					ball->vx = -ball->vx;
				}

		// Ball intersects Brick after moving Y
		ball->sprite.move(0, ball->vy);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 7; j++)
				if (ball->sprite.getGlobalBounds().intersects(bricks[i][j]->sprite.getGlobalBounds()))
				{
					std::cout << "Ball intersected Brick <" << j << "," << i << ">\n";
					bricks[i][j]->sprite.setPosition(sf::Vector2f(-20, -20));
					ball->vy = -ball->vy;
				}

		// Ball intersects Paddle
		if (ball->sprite.getGlobalBounds().intersects(paddle.sprite.getGlobalBounds()))
		{
			//ball->calculateVX(ball->sprite.getPosition(), paddle.sprite.getPosition());

			ball->vx = (ball->sprite.getPosition().x - (paddle.sprite.getPosition().x + paddle.sprite.getGlobalBounds().width / 2)) / 25;

			ball->vy = (ball->vy > 0) ? -ball->vy : ball->vy;
		}
	}
}