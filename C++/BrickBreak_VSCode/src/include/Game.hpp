#ifndef _GAME_H_
#define _GAME_H_
#include "Level.hpp"
#include "Menu.hpp"
#include "State.hpp"
#pragma once
class Game
{
public:
	
	enum GAME_STATE
	{
		MENU,
		LEVEL,
		OPTIONS
	};

	Level levelState;
	Menu menuState;
	State activeState;
	GAME_STATE state;

	Game();

	 void input(sf::Event& event, sf::RenderWindow& window);
	 void update();
	 void draw(sf::RenderWindow& window);

	 void changeState(GAME_STATE state);
};
#endif