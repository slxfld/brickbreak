#include "Menu.hpp"
#include "State.hpp"
#include <iostream>

Menu::Menu(RessourceLoader *rl)
{
	Menu::rl = rl;
	std::cout << "<Menu> create\n";
	setupButtons(rl);
	selecter.setTexture(rl->SELECT_tex);
	selecter.setPosition(sf::Vector2f(310, 256 + (buttonSelectIndex * 50)));
}

void Menu::setupButtons(RessourceLoader *rl)
{
	startButton.setTexture(rl->BUTTON_PLAY_UP_tex);
	startButton.setPosition(sf::Vector2f(400 - (startButton.getGlobalBounds().width  / 2), 300));

	optionsButton.setTexture(rl->BUTTON_OPTIONS_UP_tex);
	optionsButton.setPosition(sf::Vector2f(400 - (optionsButton.getGlobalBounds().width / 2), 350));

	exitButton.setTexture(rl->BUTTON_EXIT_UP_tex);
	exitButton.setPosition(sf::Vector2f(400 - (exitButton.getGlobalBounds().width / 2), 400));

	for (int i = 0; i < 3; i++)
		buttonTime[i] = 0;
}

void Menu::input(sf::Event& event, sf::RenderWindow &window)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		selecter.setPosition(sf::Vector2f(-900,-900));
		switch (buttonSelectIndex)
		{
			case 1: pressButton(0); break;
			case 2: pressButton(1); break;
			case 3: pressButton(2); break;
		}
	}
	
	if (event.type == sf::Event::MouseMoved)
	{
		double window_width = window.getSize().x;
		double window_height = window.getSize().y;
		
		double real_mouse_x = ((double)sf::Mouse::getPosition(window).x / (double)window_width) * 800;
		double real_mouse_y = (((double)sf::Mouse::getPosition(window).y / (double)window_height) * 640) - 20;

		if (startButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			selecter.setPosition(sf::Vector2f(310, 252 + (1 * 50)));
		}
		if (optionsButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			selecter.setPosition(sf::Vector2f(310, 252 + (2 * 50)));
		}
		if (exitButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)))
		{
			selecter.setPosition(sf::Vector2f(310, 252 + (3 * 50)));
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		double window_width = window.getSize().x;
		double window_height = window.getSize().y;
		
		double real_mouse_x = ((double)sf::Mouse::getPosition(window).x / (double)window_width) * 800;
		double real_mouse_y = (((double)sf::Mouse::getPosition(window).y / (double)window_height) * 640) - 20;

		if (startButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			pressButton(0);
		}
		if (optionsButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			pressButton(1);
		}
		if (exitButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)))
		{
			pressButton(2);
		}
	}
}



void Menu::pressButton(int index)
{
	selecter.setPosition(sf::Vector2f(-200, -200));
	switch (index)
	{
		case 0:
			buttonTime[0] = 30;
			startButton.setTexture(rl->BUTTON_PLAY_DN_tex);
		break;
		case 1:
			buttonTime[1] = 30;
			optionsButton.setTexture(rl->BUTTON_OPTIONS_DN_tex);
			break;
		case 2:
			buttonTime[2] = 30;
			exitButton.setTexture(rl->BUTTON_EXIT_DN_tex);
			break;
	}
}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(startButton);
	window.draw(optionsButton);
	window.draw(scoreButton);
	window.draw(exitButton);
	window.draw(selecter);
}

void Menu::update()
{
	for (int i = 0; i < 3; i++)
		if (buttonTime[i] > 0)
		{
			buttonTime[i]--;
			if (buttonTime[i] == 0)
			{
				if (i == 0)
				{
					startButton.setTexture(rl->BUTTON_PLAY_UP_tex);
					enterGame = true;
				}
				else if (i == 1)
					optionsButton.setTexture(rl->BUTTON_OPTIONS_UP_tex);
				else if (i == 2)
					exitButton.setTexture(rl->BUTTON_EXIT_UP_tex);
			}
		}
}