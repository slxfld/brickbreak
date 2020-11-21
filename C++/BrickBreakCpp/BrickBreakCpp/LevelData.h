#pragma once
class LevelData
{
public:
	int lives;
	int score;
	int currentLevel;
	int combo;
	int combo_mult;
	int speed;

	LevelData();
	void setDefault();
};

