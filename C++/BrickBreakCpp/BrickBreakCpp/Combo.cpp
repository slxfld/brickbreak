#include "Combo.h"

Combo::Combo(RessourceLoader* rl)
{
	text.setFont(rl->font);
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

		if (comboSize > 0)
			comboSize -= 0.025;

		if (comboTime == 0)
			combo = 0;
	}
}

void Combo::draw(sf::RenderWindow& window)
{
	if (comboTime > 0)
	{
		text.setScale(sf::Vector2f(0.7 + (comboSize), 0.7 + (comboSize)));
		window.draw(text);
		window.draw(comboBar);
	}
}

void Combo::addCombo(int value)
{
	combo += (value / 100);
	comboTime += 50;
	comboSize = 0.3;
}
