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
	FadingScore(sf::Vector2f position, int score);

	void draw();
	void update();
};

#endif