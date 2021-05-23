#ifndef _GameOver_H_
#define _GameOver_H_
#include "GameObject.hpp"
#pragma once
class GameOver : public GameObject
{
	public:
    GameOver();

    sf::Text GameOverText;
    sf::Text highscoreText;
    sf::Text scoreText;
    sf::Text enterToContinueText;

    int alphaCounter = 0;
    int alphaItemIndex = 1;
    bool show = false;

    void draw();
    void update();
    void reset();

};
#endif