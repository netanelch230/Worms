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

void Artilary::runFeature(sf::Event& event,sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		case sf::Mouse::Button::Left:
			float MouseX = sf::Mouse::getPosition(window).x;
			auto pos = sf::Vector2f{ MouseX,0 };
			setPosition(pos);
			break;
		break;
	}
	
}