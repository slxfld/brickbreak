#ifndef _COMBO_H_
#define _COMBO_H_
#include "GameObject.h"
#include "RessourceLoader.h"
#include "LevelData.h"
#pragma once
class Combo : public GameObject
{
	public:

	sf::Text text;	
	sf::RectangleShape comboBar;

	double comboTime = 100;
	double comboExtraTime = 0;
	double comboSize = 0;
	int combo = 0;
	int combo_R = 0;
	int combo_G = 0;
	int combo_B = 0;

	Combo(RessourceLoader *rl);

	void update();
	void draw(sf::RenderWindow& window);

	void addCombo(int value);
};
#endif
