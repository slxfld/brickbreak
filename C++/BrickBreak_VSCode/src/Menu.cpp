#include "Menu.hpp"
#include "State.hpp"
#include <iostream>

Menu::Menu()
{
	std::cout << "<Menu> created\n";
	setupButtons();
	selecter.setTexture(Access::rl->SELECT_tex);
	selecter.setPosition(sf::Vector2f(310, 256 + (buttonSelectIndex * 50)));
}

void Menu::setupButtons()
{
	startButton.setTexture(Access::rl->BUTTON_START_tex);
	startButton.setPosition(sf::Vector2f(400 - (startButton.getGlobalBounds().width  / 2), 300));

	optionsButton.setTexture(Access::rl->BUTTON_OPTIONS_tex);
	optionsButton.setPosition(sf::Vector2f(400 - (optionsButton.getGlobalBounds().width / 2), 350));

	exitButton.setTexture(Access::rl->BUTTON_EXIT_tex);
	exitButton.setPosition(sf::Vector2f(400 - (exitButton.getGlobalBounds().width / 2), 400));
}

void Menu::input(sf::Event& event, sf::RenderWindow &window)
{	
	if (event.type == sf::Event::MouseMoved)
	{
		double window_width = window.getSize().x;
		double window_height = window.getSize().y;
		
		double real_mouse_x = ((double)sf::Mouse::getPosition(window).x / (double)window_width) * 800;
		double real_mouse_y = (((double)sf::Mouse::getPosition(window).y / (double)window_height) * 640) - 20;

		if (startButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			selecter.setPosition(sf::Vector2f(310, 255 + (1 * 50)));
		}
		else if (optionsButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			selecter.setPosition(sf::Vector2f(310, 255 + (2 * 50)));
		}
		else if (exitButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)))
		{
			selecter.setPosition(sf::Vector2f(310, 255 + (3 * 50)));
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
			enterGame = true;
		}
		else if (optionsButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)) )
		{
			
		}
		else if (exitButton.getGlobalBounds().contains(sf::Vector2f(real_mouse_x,real_mouse_y)))
		{
			window.close();
		}
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
}