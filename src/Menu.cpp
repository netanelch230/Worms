#include "Menu.h"
#include <iterator>     // std::distance
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


Menu::Menu()
{
	initializeColors();
}
void Menu::run(sf::Texture& menuScreen, sf::RenderWindow& window)
{
	m_sprite.setTexture(menuScreen);
	while (window.isOpen())
	{
		window.clear();
		window.draw(m_sprite);
		for (auto i : m_groupColors)
			window.draw(i);
		intializedefinitions(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonReleased:
				{
					const auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
					/*switch (event.mouseButton.button)
					{
					case sf::Mouse::Button::Left:
					case sf::Mouse::Button::Right:
					}*/
					if (m_playerText.getLocalBounds().contains(location))
					{
						while (sf::Event::TextEntered)
						{
							m_playerInput += static_cast<char>(event.text.unicode);
							m_playerText.setString(m_playerInput);
							window.draw(m_playerText);
							window.display();
						}
					}
					break;
				}

			}
		}
	}
}
void Menu::initializeColors()
{
	m_groupColors.resize(colorAmount);
	for (auto c = m_groupColors.begin(); c!= m_groupColors.end(); ++c)
	{
		auto currLocation = std::distance(m_groupColors.begin(), c);
		c->setFillColor(getColor(currLocation));
		c->setSize(sf::Vector2f{ 50,50 });
		c->setPosition((70* currLocation), 630);
		c->setOutlineColor(sf::Color::Black);
	}
}

void Menu::intializedefinitions(sf::RenderWindow& window)
{
	std::vector<std::string> menuOptions;
	createTextOptions(menuOptions);
	initializeGameFormat(menuOptions[0], window);
	initializeColors();
	
}

void Menu::initializeGameFormat(std::string curr, sf::RenderWindow& window)
{
	sf::RectangleShape rec;
	rec.setFillColor(sf::Color::White);
	rec.setSize(sf::Vector2f{ 50,50 });
	rec.setPosition(100, 100);
	m_playerText.setCharacterSize(25);
	m_playerText.setFillColor(sf::Color::Black);
	m_playerText.setStyle(sf::Text::Bold);
	m_playerText.setOrigin(0, 10);
	m_playerText.setPosition(100, 100);
	window.draw(rec);
	window.draw(m_playerText);

	m_headLine.setString(curr);
	m_headLine.setCharacterSize(20);
	m_headLine.setFillColor(sf::Color::Black);
	m_headLine.setStyle(sf::Text::Bold);
	m_headLine.setOrigin(0, 10);
	m_headLine.setPosition(10, 10);
	window.draw(m_headLine);
	
	// 2 options
	m_gameFormat.resize(2);
	for (auto c = m_gameFormat.begin(); c!= m_gameFormat.end(); ++c)
	{
		auto currLocation = std::distance(m_gameFormat.begin(), c);
		c->setFillColor(sf::Color::Black);
		c->setSize(sf::Vector2f{ 50,50 });
		c->setPosition((70* currLocation), 30);
		c->setOutlineColor(sf::Color::White);
	}
}


sf::Color Menu::getColor(int colorNum)
{
	switch(colorNum)
	{
		case 0:
			return sf::Color::Red;
		case 1:
			return sf::Color::Red+sf::Color::Blue;
		case 2:
			return sf::Color::Blue;
		case 3:
			return sf::Color::Green;
	}
}

void Menu::setFont(sf::Font& font)
{
	m_headLine.setFont(font);
}


void Menu::createTextOptions(std::vector<std::string>& menuOptions)
{
	std::string curr = "choose the game format: ......."; // sapir
	menuOptions.push_back(curr);
	curr = "choose the game background"; // sapir
	menuOptions.push_back(curr);
	curr = "choose number of players"; // noa - numberOfPlayers+ names.x
	menuOptions.push_back(curr);
	curr = "choose color:"; // sapir
	menuOptions.push_back(curr);
}
