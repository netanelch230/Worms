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
	m_groupColors.resize(colorsOptions);
	initializeColors();
	setResources();
}
bool Menu::run(sf::RenderWindow& window)
{
	int pressed;
	while (window.isOpen())
	{
		window.clear();
		drawMenu(window);
		window.display();
		auto event = sf::Event{};
		if (window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					m_currGroup++;
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					m_playerInput[m_currGroup].erase(m_playerInput[m_currGroup].getSize() - 1,
						m_playerInput[m_currGroup].getSize());
					m_playerText[m_currGroup].setString(m_playerInput[m_currGroup]);
				}
				else if (m_currGroup <= m_groupAmount)
				{
					m_playerInput[m_currGroup] += event.text.unicode;
					m_playerText[m_currGroup].setString(m_playerInput[m_currGroup]);
				}
				break;
			case sf::Event::Closed:
				window.close();
				return false;
				break;
			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					pressed = updatePress(location);
					if (pressed == t_end)
					{
						window.close();
					}
					if (pressed == t_startPlay)
					{
						setMenuParameters();
						return true;
					}
						break;
				}
			
			}
		}
	}
	
}

int Menu::updatePress(sf::Vector2f location)
{
	for (auto i = 0; i < m_playersSprite.size(); i++)
	{
		if (m_playersSprite[i].getGlobalBounds().contains(location.x, location.y))
		{
			initializeColors();
			m_groupAmount = i+1;
			for (int j = 0; j <= i; j++)
			{
				m_textFields[j].setFillColor(sf::Color::White);
				m_groupColors[j].setFillColor(getColor(j));
			}
			break;
		}
	}

	if (m_background1.getGlobalBounds().contains(location.x, location.y))
		m_menuParameters.m_background = backGround1pic;

	if (m_background2.getGlobalBounds().contains(location.x, location.y))
		m_menuParameters.m_background = backGround2pic;


	if (m_playWithComp.getGlobalBounds().contains(location.x, location.y))
		m_menuParameters.m_gameFormat = true;


	if (m_playWithFriend.getGlobalBounds().contains(location.x, location.y))
		m_menuParameters.m_gameFormat = false;
	

	//if (m_playWithFriend.getGlobalBounds().contains(location.x, location.y))
	//	return t_end;

	if (m_startPlay.getGlobalBounds().contains(location.x, location.y))
		return t_startPlay;

	
	return t_update;
}

void Menu::setMenuParameters()
{
	m_menuParameters.m_playersColor.resize(m_groupAmount);
	m_menuParameters.m_playerName.resize(m_groupAmount);
	m_menuParameters.m_numOfPlayers = m_groupAmount;
	for (auto i = 0; i < m_groupAmount; ++i)
	{
		m_menuParameters.m_playerName[i] = std::string(m_playerInput[i]);
		m_menuParameters.m_playersColor[i] = getColor(i);
	}
}
void Menu::initializeColors()
{
	for (auto c = m_groupColors.begin(); c != m_groupColors.end(); ++c)
	{
		auto currLocation = std::distance(m_groupColors.begin(), c);
		c->setFillColor(sf::Color::Transparent);
		c->setSize(sf::Vector2f{ 40 ,40 });
		c->setPosition(700, 380 + 70 * currLocation);
		c->setOutlineColor(sf::Color::Black);
	}
}

void Menu::setPlayerTextField()
{
	m_playerInput.resize(maxTextFields);
	m_playerText.resize(maxTextFields);

	for (auto i = 0; i < maxTextFields; i++)
		m_textFields.push_back(createRectangleShape(i));

	int j = 0;
	for (auto i = 0; i < m_playerText.size(); i++)
	{
		m_playerText[i].setCharacterSize(25);
		m_playerText[i].setFillColor(sf::Color::Black);
		m_playerText[i].setStyle(sf::Text::Bold);
		m_playerText[i].setOrigin(0, 10);
		m_playerText[i].setPosition(505, 393 + j);
		j += 70;
	}

}

sf::RectangleShape Menu::createRectangleShape(int row)
{
	sf::RectangleShape rec;
	rec.setFillColor(sf::Color::Transparent);
	rec.setSize(sf::Vector2f{ 150, 40 });
	rec.setPosition(500, 380 + (row * 70));
	return rec;
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(m_spriteBackGround);
	window.draw(m_spriteHeadline);
	window.draw(m_playWithComp);
	window.draw(m_playWithFriend);
	window.draw(m_background1);
	window.draw(m_background2);

	for (auto i : m_playersSprite)
		window.draw(i);
	for (auto i : m_groupColors)
		window.draw(i);

	for (auto i : m_background)
		window.draw(i);

	for (auto i = 0; i <= m_groupAmount; i++)
	{
		window.draw(m_textFields[i]);
	}

	for (auto i = 0; i < m_playerText.size(); ++i)
	{
		window.draw(m_playerText[i]);
	}

	//draw all head lines!
	for (auto i : m_headLines)
		window.draw(i);
	window.draw(m_startPlay);

}


sf::Color Menu::getColor(int colorNum)
{
	switch (colorNum)
	{
	case 0:
		return sf::Color::Red;
	case 1:
		return sf::Color::Red + sf::Color::Blue;
	case 2:
		return sf::Color::Blue;
	case 3:
		return sf::Color::Green;
	}
}

void Menu::setResources()
{
	for (auto i = 0; i < m_headLines.size(); i++)
		m_headLines[i].setFont(Resources::instance().getfont(menu_font));

	for (auto i = 0; i < m_playerText.size(); ++i)
		m_playerText[i].setFont(Resources::instance().getfont(menu_font));
	
	m_spriteBackGround.setTexture(Resources::instance().getMenuTexture(menuPic));
	m_spriteHeadline.setTexture(Resources::instance().getMenuTexture(menuHeadline));
	m_spriteHeadline.setPosition(250, 0);
	m_playWithComp.setTexture(Resources::instance().getMenuTexture(playWithComputerPic));
	m_playWithComp.setPosition(10, 200);
	m_playWithFriend.setTexture(Resources::instance().getMenuTexture(playWithFriendsPic));
	m_playWithFriend.setPosition(10, 400);
	m_background1.setTexture(&Resources::instance().getMenuTexture(backGround1pic));
	m_background1.setPosition(900, 200);
	m_background1.setSize({ 250,200 });
	m_background2.setTexture(Resources::instance().getMenuTexture(backGround2pic));
	m_background2.setPosition(900, 400);
	m_startPlay.setSize({ 100, 70 });
	m_startPlay.setTexture(&Resources::instance().getMenuTexture(startPlay));
	m_startPlay.setPosition(750, 600);


	sf::Sprite s;
	m_playersSprite.resize(Resources::instance().sizeOfPlayers());
	for (auto i = 0; i < m_playersSprite.size(); i++)
	{
		m_playersSprite[i].setTexture(Resources::instance().getPlayersTextures(i));
		m_playersSprite[i].setPosition(playersBottonX + (i * playersBottonXRatio), playersBottonY);
	}

}

void Menu::setTextFieldsHeadlines()
{
	m_headLines.resize(maxHeadlines);

	int currHeadLine = 0;
	setHeadLine(currHeadLine++, "Choose game format");
	m_headLines[gameFormat].setPosition(gameFormatX, 150);
	setHeadLine(currHeadLine++, "Choose game background");
	m_headLines[gameBackground].setPosition(900, 150);
	setHeadLine(currHeadLine++, "Choose number of players");
	m_headLines[numberOfPlayers].setPosition(440, 190);
	setHeadLine(currHeadLine++, "Enter group name");
	m_headLines[groupName].setPosition(470, 350);
}

void Menu::setHeadLine(const int index, std::string headLine)
{
	m_headLines[index].setString(headLine);
	m_headLines[index].setCharacterSize(30);
	m_headLines[index].setFillColor(sf::Color::Black);
	m_headLines[index].setStyle(sf::Text::Bold);
	m_headLines[index].setOrigin(0, 10);
}
