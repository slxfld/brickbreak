#include "FadingScore.hpp"

FadingScore::FadingScore(sf::Vector2f position, int score ,RessourceLoader *rl)
{
	text.setFont(rl->font);
	text.setString("+" + std::to_string(score));
	text.setPosition(position);

	velocity = 10;
}

void FadingScore::update()
{
	text.move(0,-velocity);
	text.setColor(sf::Color(255,255,255,velocity * 150.0));
	if (velocity > 0)  
		velocity-=0.5;
	else 
		delete_me = true;
}

void FadingScore::draw(sf::RenderWindow& window)
{
	if(velocity > 0) window.draw(text);
}