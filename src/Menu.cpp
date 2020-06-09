#include "Menu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <utility>
#include <iterator>     // std::distance
Menu::Menu()
{
	setPlayerTextField();
	setTextFieldsHeadlines();
	initializeColors();
	initializeBackground();
	initializeGameFormat();
}
void Menu::run(sf::RenderWindow& window)
{
	LoadImages();
	setOptions();
	while (window.isOpen())
	{
		window.clear();
		drawMenu(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					m_currGroup++;
				}
				else
				{
					if (m_currGroup <= m_groupAmount)
					{
						m_playerInput[m_currGroup] += event.text.unicode;
						m_playerText[m_currGroup].setString(m_playerInput[m_currGroup]);
					}
				}
				break;
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonReleased:
				{
					auto location = window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });
					switch (event.mouseButton.button)
					{
					case sf::Mouse::Button::Left:
						updatePress(location);
						/*if (pressed == t_end)
						{
							window.close();
						}
						continue to play
						*/
					}
				}
			}
		}
	}
}

void Menu::updatePress(sf::Vector2f location)
{
	for (auto i = 0; i < m_playersSprite.size(); i++)
	{
		if (m_playersSprite[i].getGlobalBounds().contains(location.x, location.y))
		{
			m_groupAmount = i;
			for (int j = 0; j <= i; j++)
			{
				m_textFields[j].setFillColor(sf::Color::White);
			}
			break;
		}
	}
	if (m_background1.getGlobalBounds().contains(location.x, location.y))
		values.m_background= 1;

	if (m_background2.getGlobalBounds().contains(location.x, location.y))
		values.m_background = 2;
		
	if (m_playWithComp.getGlobalBounds().contains(location.x, location.y))
		values.m_gameFormat = true;

	if (m_playWithFriend.getGlobalBounds().contains(location.x, location.y))
		values.m_gameFormat = false;

}

void Menu::initializeColors()
{
	
	m_headLines[groupColor].setPosition(300, 580);

	m_groupColors.resize(colorsOptions);
	for (auto c = m_groupColors.begin(); c!= m_groupColors.end(); ++c)
	{
		auto currLocation = std::distance(m_groupColors.begin(), c);
		c->setFillColor(getColor(currLocation));
		c->setSize(sf::Vector2f{ 75 ,75 });
		c->setPosition((300 + 100 * currLocation), 620);
		c->setOutlineColor(sf::Color::Black);
	}
}

void Menu::setPlayerTextField()
{
	m_playerInput.resize(maxTextFields);
	m_playerText.resize(maxTextFields);

	for (auto i = 0; i < maxTextFields; i++)
	{
		m_textFields.push_back(createRectangleShape(i));
	}

	int j = 0;
	for (auto i = 0; i < m_playerText.size(); i++)
	{
		m_playerText[i].setCharacterSize(25);
		m_playerText[i].setFillColor(sf::Color::Black);
		m_playerText[i].setStyle(sf::Text::Bold);
		m_playerText[i].setOrigin(0, 10);
		m_playerText[i].setPosition(500, 350+j);
		j += 70;
	}

}

sf::RectangleShape Menu::createRectangleShape(int row)
{
	sf::RectangleShape rec;
	rec.setFillColor(sf::Color::Transparent);
	rec.setSize(sf::Vector2f{ 150, 50 });
	rec.setPosition(500, 330+(row*70));
	return rec;
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(m_spriteBackGround);
	window.draw(m_spriteHeadline);
	window.draw(m_playWithComp);
	window.draw(m_playWithFriend);

	for (auto i : m_playersSprite)
		window.draw(i);
	for (auto i : m_groupColors)
		window.draw(i);
	
	for (auto i : m_background)
		window.draw(i);

	for (auto i : m_gameFormat)
		window.draw(i);
	

	for (auto i = 0; i <= m_groupAmount; i++)
	{
		window.draw(m_textFields[i]);
	}

	for (auto i = 0 ; i < m_playerText.size(); ++i)
	{
		window.draw(m_playerText[i]);
	}

	//draw all head lines!
	for (auto i : m_headLines)
		window.draw(i);

}

void Menu::LoadImages()
{
	sf::Texture current;
	current.loadFromFile("PlayWithFriends.png");
	m_MenuTextures.push_back(current);
	current.loadFromFile("PlayWithComputer.png");
	m_MenuTextures.push_back(current);

}

void Menu::setOptions()
{
	m_playWithComp.setTexture(m_MenuTextures[0]);
	m_playWithComp.setPosition(10, 200);
	m_playWithFriend.setTexture(m_MenuTextures[1]);
	m_playWithFriend.setPosition(10, 400);
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

void Menu::setResources(sf::Font& font, sf::Texture& backGround, sf::Texture& headLine,
	std::vector<sf::Texture>& players) 
{
	for (auto i = 0; i < m_headLines.size(); i++)
		m_headLines[i].setFont(font);
	
	for (auto i = 0 ; i<m_playerText.size(); ++i)
		m_playerText[i].setFont(font);

	m_spriteBackGround.setTexture(backGround);
	m_spriteHeadline.setTexture(headLine);
	m_spriteHeadline.setPosition(250, 0);

	sf::Sprite s;
	m_playersSprite.resize(players.size());
	for (auto i = 0; i < players.size(); i++)
	{
		m_playersSprite[i].setTexture(players[i]);
		m_playersSprite[i].setPosition(300+(i*150), 200);
	}
}

void Menu::setTextFieldsHeadlines()
{
	m_headLines.resize(maxHeadlines);
	int currHeadLine = 0;
	setHeadLine(currHeadLine++, "Choose game format");
	setHeadLine(currHeadLine++, "Choose game background");
	setHeadLine(currHeadLine++, "Choose number of players");
	setHeadLine(currHeadLine++, "Choose game color");
	setHeadLine(currHeadLine++, "Enter group name");
}


void Menu::initializeBackground()
{
	m_headLines[gameBackground].setPosition(900, 150);
	//m_playWithComp.setTexture()
	m_background.resize(backgroundOptions);
	for (auto c = m_background.begin(); c!= m_background.end(); ++c)
	{
		auto currLocation = std::distance(m_background.begin(), c);
		c->setFillColor(getColor(currLocation));
		c->setSize(sf::Vector2f{ 250,200 });
		c->setPosition(900 , 200 + (200*currLocation));
		c->setOutlineColor(sf::Color::Black);
	}
}


void Menu::setHeadLine(const int index, std::string headLine)
{
	m_headLines[index].setString(headLine);
	m_headLines[index].setCharacterSize(30);
	m_headLines[index].setFillColor(sf::Color::Black);
	m_headLines[index].setStyle(sf::Text::Bold);
	m_headLines[index].setOrigin(0, 10);
	m_headLines[index].setPosition(10, 30*(index+10));
}

void Menu::initializeGameFormat()
{
	m_headLines[gameFormat].setPosition(10, 150);

	m_gameFormat.resize(gameFormatOptions);
	
	for (auto c = m_gameFormat.begin(); c!= m_gameFormat.end(); ++c)
	{
		auto currLocation = std::distance(m_gameFormat.begin(), c);
		c->setFillColor(getColor(currLocation));
		c->setSize(sf::Vector2f{ 250 ,200 });
		c->setPosition(10 , 200 + 200 * currLocation); 
		c->setOutlineColor(sf::Color::Black);
	}
	
}