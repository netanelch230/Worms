#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Resources.h"
#include "Enum.h"
#include <iterator>     // std::distance
#include <string>

struct Input
{
	unsigned int m_numOfPlayers;
	bool m_gameFormat = true;			 // with copmuter or not
	unsigned int m_background = backGround1pic;
	std::vector<std::string> m_playerName;
	std::vector<sf::Color> m_playersColor;
};

class Menu
{
public:
	Menu();
	bool run(sf::RenderWindow& window);
	Input getInput() { return m_menuParameters; };
	sf::Color getColor(int colorNum);

private:
	void setHeadLine(const int index, std::string headLine);
	void drawMenu(sf::RenderWindow& window);
	void setPlayerTextField();
	void setResources();
	sf::RectangleShape createRectangleShape(int row);
	void setTextFieldsHeadlines();
	void initializeColors();
	void setMenuParameters();
	//===================================================================================
	//used for the player input 
	std::vector<sf::Text> m_playerText;
	std::vector<sf::String> m_playerInput;
	//===================================================================================
	std::vector<sf::RectangleShape> m_groupColors;
	std::vector<sf::RectangleShape> m_gameFormat;
	std::vector<sf::RectangleShape> m_background;
	//===================================================================================
	sf::Sprite m_spriteHeadline;
	sf::Sprite m_spriteBackGround;
	std::vector<sf::Sprite> m_playersSprite;
	std::vector<sf::RectangleShape> m_textFields;
	//this index will be the index of the curr group which enter the name of the group
	int m_currGroup = 0;
	int m_groupAmount = 0;
	//for the headlines of menu fields
	std::vector<sf::Text> m_headLines;
	Input m_menuParameters;
	int updatePress(sf::Vector2f location);
	sf::RectangleShape m_background1;
	sf::Sprite m_background2;
	sf::Sprite m_playWithComp;
	sf::Sprite m_playWithFriend;
	sf::RectangleShape m_start;
	sf::RectangleShape m_exit;
	std::vector<sf::Texture> m_MenuTextures;
};
