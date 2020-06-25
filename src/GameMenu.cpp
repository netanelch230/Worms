#pragma once
#include "GameMenu.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <utility>
#include <iterator> // std::distance

//c-tor of Game menu 
GameMenu::GameMenu()
{
	setPlayerTextField();
	m_groupColors.resize(colorsOptions); //set the maximum color groups options
	initializeColors();
	setResources();
	buildButtons();
}

/*this function will run two menus. the first menu is to give
the player or the groups an option if he wants to player
or if he wants to exit.
if he wants to play, second menu will open.
and the groups will need to choose how many groups they want.
respectively, we'll open the amount of text field so
each group will write the group name and will get
the color.
in addition, there are two options for background
the first one is Jerusalem, the second is the Desert.*/
bool GameMenu::run(sf::RenderWindow& window)
{
	drawFirstMenu(window);
	while (!(m_startGame = optionsEvents(window)))
	{
		if (window.isOpen())
			drawFirstMenu(window);
		else
			return false;
	}
	if (m_startGame)
	{
		while (window.isOpen())//if were here it means the player wants to start
		{
			drawSecondMenu(window);

			if (checkEvent(window))
				return true;
		}
	}
	return false;
}

sf::Color GameMenu::getColor(int colorNum) const
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

bool GameMenu::optionsEvents(sf::RenderWindow& window)
{
	sf::Vector2f mousePos; //our mouse position

	while (window.isOpen())
	{
		auto event = sf::Event{};
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); //close the window
				return false;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left)	//if we pressed on left mouse
				{
					//we need to save mouse position
					mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }); //the mouse position

					if (m_playButton->contains(mousePos))	//clicked on play button
						return true; //close the game menu and start to play

					else if (m_exitButton->contains(mousePos))	//clicked on exit button
					{
						window.close();
						return false;	//close menu window
					}
				}
				break;

			case sf::Event::MouseMoved:	//if the mouse only move (with out press)
				mousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				if (m_playButton->contains(mousePos))//mouse on play button place
					m_playButton->moveButton(posPlayButton);//bold play button
				else
					m_playButton->unMoveButton(posPlayButton);
				if (m_exitButton->contains(mousePos))//mouse on exit button
					m_exitButton->moveButton(posExitButton);	//bold  exit button
				else
					m_exitButton->unMoveButton(posExitButton);
				return false;
			}
		}
	}
	return true;
}

bool GameMenu::updatePress(sf::Vector2f location)
{
	for (auto i = 0; i < m_playersButtons.size(); i++)
	{
		if (m_playersButtons[i]->contains(location))
		{
			initializeColors();
			m_groupAmount = i;
			for (int j = 0; j <= i; j++)
			{
				m_textFields[j].setFillColor(sf::Color::White);
				m_groupColors[j].setFillColor(getColor(j));
			}
			break;
		}
	}
	if (m_map1->contains(location))
		m_menuParameters.m_background = jeruBack;

	if (m_map2->contains(location))
		m_menuParameters.m_background = desertBack;

	if(m_playWithComp->contains(location))
		m_menuParameters.m_gameFormat = true;

	if(m_playWithFriend->contains(location))
		m_menuParameters.m_gameFormat = false;

	if (m_playGameButton->contains(location))
	{
		setMenuParameters();
		return true;
	}
	return false;
}

bool GameMenu::checkEvent(sf::RenderWindow& window)
{
	sf::Vector2f mousePos; //our mouse position
	while (window.isOpen())
	{
		auto event = sf::Event{};
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); //close the window
				return false;

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
				return false;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left)	//if we pressed on left mouse
				{
					//we need to save mouse position
					mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }); //the mouse position
					return updatePress(mousePos);
				}
				return true;

			case sf::Event::MouseMoved:	//if the mouse only move (with out press)
				mousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });

				if (m_playWithComp->contains(mousePos))//mouse on play button place
					m_playWithComp->moveButton(posPlayCompButton);//bold play button
				else
					m_playWithComp->unMoveButton(posPlayCompButton);

				if (m_playWithFriend->contains(mousePos))
					m_playWithFriend->moveButton(posPlayFriendButton);	
				else
					m_playWithFriend->unMoveButton(posPlayFriendButton);

				if (m_map1->contains(mousePos))
					m_map1->moveButton(map1Button);	
				else
					m_map1->unMoveButton(map1Button);
				if (m_map2->contains(mousePos))
					m_map2->moveButton(map2Button);	
				else
					m_map2->unMoveButton(map2Button);
				if (m_playGameButton->contains(mousePos))
					m_playGameButton->moveButton(playButtonPos);	
				else
					m_playGameButton->unMoveButton(playButtonPos);

				for (int i=0; i<m_playersButtons.size(); i++)
				{
					if (m_playersButtons[i]->contains(mousePos))
						m_playersButtons[i]->moveButton({ playerButtonPos.x + (i * playerDistance), playerButtonPos.y });

					else
						m_playersButtons[i]->unMoveButton({ playerButtonPos.x + (i * playerDistance), playerButtonPos.y });
				}
				return false;
			}
		}
	}
}

void GameMenu::drawFirstMenu(sf::RenderWindow& window) const
{
	window.clear();
	window.draw(m_spriteBackgraound1);
	m_playButton->draw(window);
	m_exitButton->draw(window);
	window.display();

}

void GameMenu::drawSecondMenu(sf::RenderWindow& window) const
{
	window.clear();
	window.draw(m_spriteBackgraound2);
	m_playWithComp->draw(window);
	m_playWithFriend->draw(window);
	m_map1->draw(window);
	m_map2->draw(window);
	m_playGameButton->draw(window);

	for (int i = 0; i < m_playersButtons.size(); i++)
		m_playersButtons[i]->draw(window);

	for (auto i = 0; i <= m_groupAmount; i++)
	{
		window.draw(m_groupColors[i]);
		window.draw(m_textFields[i]);
	}

	for (auto i = 0; i < m_hedlinesSprite.size(); i++)
		window.draw(m_hedlinesSprite[i]);

	for (auto i = 0; i < m_playerText.size(); ++i)
	{
		window.draw(m_playerText[i]);
	}

	//draw all head lines!
	for (auto i : m_headLines)
		window.draw(i);

	window.display();
}

void GameMenu::buildButtons()
{
	m_playButton = std::make_unique <Button>(m_spritePlay, posPlayButton);
	m_exitButton = std::make_unique <Button>(m_spriteExit, posExitButton);
	m_playWithComp = std::make_unique <Button>(m_spriteComp, posPlayCompButton);
	m_playWithFriend = std::make_unique <Button>(m_spriteFriend, posPlayFriendButton);
	m_map1 = std::make_unique <Button>(m_spriteMap1, map1Button);
	m_map2 = std::make_unique <Button>(m_spriteMap2, map2Button);
	m_playGameButton = std::make_unique <Button>(m_playGame, playButtonPos);

	m_playersButtons.resize(4);
	for (auto i = 0; i < m_playersSprite.size(); i++)
	{
		m_playersButtons [i] = std::make_unique <Button>(m_playersSprite[i], m_playersSprite[i].getPosition());
	}
}

/*this function will set the player text field - the maximum text field is for
4 group players and we'll set them to transperent color till the players will press
on the wanted amount of groups and then we'll change the color of the text field.
based on the amount of players.
in addition, were setting here all the setting of the text field.*/
void GameMenu::setPlayerTextField()
{
	//m_player input used for the input we'll get from the keyboard. (sf::String)
	m_playerInput.resize(maxTextFields); //can insert it for event of keyboard.
	//we'll insert player input to player text (set string of player text to player input)
	m_playerText.resize(maxTextFields);// we'll save the text we got from the user. sf::Text.

	//set the text field rectangle
	for (auto i = 0; i < maxTextFields; i++)
		m_textFields.push_back(createRectangleShape(i));

	int j = 0;
	//set the text field - text!
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

sf::RectangleShape GameMenu::createRectangleShape(int row) const
{
	sf::RectangleShape rec;
	rec.setFillColor(sf::Color::Transparent);
	rec.setSize(sf::Vector2f{ 150, 40 });
	rec.setPosition(500, 380 + (row * 70));
	return rec;
}

void GameMenu::setTextFieldsHeadlines()
{
	m_headLines.resize(maxHeadlines);
	int currHeadLine = 0;
	setHeadLine(currHeadLine++, "Choose game format");
	m_headLines[gameFormat].setPosition(gameFormatX, 150);
	setHeadLine(currHeadLine++, "Choose game background");
	m_headLines[gameBackground].setPosition(900, 150);
	setHeadLine(currHeadLine++, "Choose number of players");
	m_headLines[numberOfPlayers].setPosition(440, 170);
}

void GameMenu::setHeadLine(const int index, std::string headLine)
{
	m_headLines[index].setString(headLine);
	m_headLines[index].setCharacterSize(30);
	m_headLines[index].setFillColor(sf::Color::Black);
	m_headLines[index].setStyle(sf::Text::Bold);
	m_headLines[index].setOrigin(0, 10);
}

/*in this function were setting all the squares of group colors to the
maximum colors options. in the beginning we don't know how many groups
we'll have so until the players will choose the group amount
all the options will be transperent*/
void GameMenu::initializeColors()
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

void GameMenu::setResources()
{
	for (auto i = 0; i < m_headLines.size(); i++)
		m_headLines[i].setFont(Resources::instance().getfont(menu_font));

	for (auto i = 0; i < m_playerText.size(); ++i)
		m_playerText[i].setFont(Resources::instance().getfont(menu_font));

	m_spriteBackgraound1.setTexture(Resources::instance().getTexture(menuPic1));
	m_spriteBackgraound2.setTexture(Resources::instance().getTexture(menuPic2));
	m_spriteComp.setTexture(Resources::instance().getTexture(playWithComputerPic));
	m_spriteFriend.setTexture(Resources::instance().getTexture(playWithFriendsPic));
	m_spriteExit.setTexture(Resources::instance().getTexture(exitGame));
	m_spritePlay.setTexture(Resources::instance().getTexture(start));
	m_spriteMap1.setTexture(Resources::instance().getTexture(backGround1pic));
	m_spriteMap2.setTexture(Resources::instance().getTexture(backGround2pic));
	m_playGame.setTexture(Resources::instance().getTexture(playgameButton));

	sf::Sprite s;
	m_playersSprite.resize(4);
	for (auto i = 0; i < m_playersSprite.size(); i++)
	{
		m_playersSprite[i].setTexture(Resources::instance().getTexture(i + 8));
		m_playersSprite[i].setPosition(playersBottonX + (i * playersBottonXRatio), playersBottonY);
	}
	m_hedlinesSprite.resize(4);
	for (auto i = 0; i < m_hedlinesSprite.size(); i++)
	{
		m_hedlinesSprite[i].setTexture(Resources::instance().getTexture(i + 46));
	}
	
	m_hedlinesSprite[0].setPosition(gameFormatPos);
	m_hedlinesSprite[1].setPosition(gameMapPos);
	m_hedlinesSprite[2].setPosition(groupNamePos);
	m_hedlinesSprite[3].setPosition(playersAmountPos);
}

void GameMenu::setMenuParameters()
{
	m_groupAmount++;
	m_menuParameters.m_playersColor.resize(m_groupAmount);
	m_menuParameters.m_playerName.resize(m_groupAmount);
	m_menuParameters.m_numOfPlayers = m_groupAmount;
	for (auto i = 0; i < m_groupAmount; ++i)
	{
		m_menuParameters.m_playerName[i] = std::string(m_playerInput[i]);
		m_menuParameters.m_playersColor[i] = getColor(i);
	}
}

