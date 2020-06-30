 #pragma once
#include "Artilary.h"

void Artilary::applyFeatures() {

	//case sf::Event::MouseButtonPressed:
	//	case sf::Mouse::Button::
	//	{
	//		float MouseX = sf::Mouse::getPosition(m_window).x;
	//		float MouseY = sf::Mouse::getPosition(m_window).y;
	//	}
}

bool Artilary::runFeature(sf::Event& event,sf::RenderWindow& window,bool& drawFeatur, const sf::Vector2f& wormPosition)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		case sf::Mouse::Button::Left:
			float MouseX = sf::Mouse::getPosition(window).x;
			auto pos = sf::Vector2f{ MouseX,0 };
			setPosition(pos);
			drawFeatur = true;
			break;
		break;
	}
	return true;
}