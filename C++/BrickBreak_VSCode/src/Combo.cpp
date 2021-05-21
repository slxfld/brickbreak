#include "Combo.hpp"

Combo::Combo()
{
	text.setFont(Access::rl->font);
	text.setScale(sf::Vector2f(0.7, 0.7));
	text.setPosition(sf::Vector2f(20, 50));

	comboBar.setSize(sf::Vector2f(10, 10));
	comboBar.setPosition(sf::Vector2f(2, 2));
	comboBar.setFillColor(sf::Color::Green);
}

void Combo::update()
{
	text.setString("Combo: " + std::to_string((int)combo) + "x");
	comboBar.setSize(sf::Vector2f(comboTime, 10));

	if (comboTime > 0)
	{
		comboTime--;
		if (comboTime == 0) {
			combo = 0;
		}
	}

	if (comboSize > 0)
		comboSize -= 0.025;
}

void Combo::draw()
{
	if (combo > 0)
	{
		text.setScale(sf::Vector2f(0.7 + (comboSize), 0.7 + (comboSize)));
		Access::window->draw(text);
		//Access::window->draw(comboBar);
	}
}

void Combo::addCombo(int value)
{
	combo++;
	comboTime = 100;
	comboSize = 0.3;
}
