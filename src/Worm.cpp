#include "Worm.h"


void Worm::move(float time)
{
	m_sprite.move(calculateDirection(time, direction()));
}

int Worm::direction()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return right;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return left;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return jump;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return down;
	
	else
		return stand;
}

sf::Vector2f Worm::calculateDirection(const float& deltaTime, const int& num)
{
	float speed = 200.f;
	switch (num)
	{
	case jump:
		return sf::Vector2f(0, 0);				//need to calculate
		break;
	case down:
		return sf::Vector2f(0, speed * deltaTime);
		break;
	case left:
		return sf::Vector2f(-speed * deltaTime, 0);
		break;
	case right:
		return sf::Vector2f(speed * deltaTime, 0);
	case stand:
		return { 0,0 };
		break;
	}
}
