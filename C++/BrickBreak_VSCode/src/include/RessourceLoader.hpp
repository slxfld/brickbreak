#ifndef _RLOADER_H_
#define _RLOADER_H_
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

#pragma once
class RessourceLoader
{
	public:

	sf::Texture BRICK_1_G1_tex;
	sf::Texture BRICK_1_B1_tex;
	sf::Texture BRICK_1_GR1_tex;
	sf::Texture BRICK_1_O1_tex;
	sf::Texture BRICK_1_R1_tex;
	sf::Texture BRICK_1_V1_tex;
	sf::Texture BRICK_1_Y1_tex;
	sf::Texture BACKGROUND_tex;
	sf::Texture MENU_tex;
	sf::Texture BLANK_MENU_tex;

	sf::Texture BUTTON_DN_tex;
	sf::Texture BUTTON_UP_tex;
	sf::Texture SELECT_tex;

	sf::Texture BUTTON_START_tex;
	sf::Texture BUTTON_OPTIONS_tex;
	sf::Texture BUTTON_EXIT_tex;

	sf::Texture MENU_BACKGROUND_tex;

	sf::Texture BALL_tex;
	sf::Texture PAD_tex;
	sf::Texture LIFE_tex;

	sf::Font font;

	sf::SoundBuffer BALL_SND;
	sf::SoundBuffer BRICK_SND;
	sf::SoundBuffer BUTTON_SND;
	sf::SoundBuffer UI_SND;
	sf::SoundBuffer LIFE_SND;
	sf::SoundBuffer LEVEL_SND;
	sf::SoundBuffer GAMEOVER_SND;
	sf::SoundBuffer POWER_SND;

	RessourceLoader();

	void load();
};
#endif