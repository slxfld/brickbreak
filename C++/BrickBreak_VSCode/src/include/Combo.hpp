#ifndef _COMBO_H_
#define _COMBO_H_
#include "GameObject.hpp"
#include "LevelData.hpp"
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

	Combo();

	void update();
	void draw(sf::RenderWindow& window);

	void addCombo(int value);
};
#endif
