#include "Level.h"
Level::Level()
{

}

Level::Level(RessourceLoader* rl)
{
	Level::rl = rl;
	std::cout << "<Level> create\n";
}

void Level::input(sf::Event& event)
{

}

void Level::draw(sf::RenderWindow& window)
{

}

void Level::collisions()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			if (ball.sprite.getGlobalBounds().intersects(bricks[i][j].sprite.getGlobalBounds()))
				std::cout << "Ball intersected Brick <" << j << "," << i << ">\n";
}

void Level::update()
{

}