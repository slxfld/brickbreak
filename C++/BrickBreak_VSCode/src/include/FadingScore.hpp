#ifndef _FSCORE_H_
#define _FSCORE_H_
#include "GameObject.hpp"
#pragma once
class FadingScore : public GameObject
{
public:

	bool alive = true;
	sf::Text text;
	double velocity;

	FadingScore();
	FadingScore(sf::Vector2f position, int score, RessourceLoader *rl);

	void draw(sf::RenderWindow& window);
	void update();
};

#endif