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
	bool m_gameFormat; // with copmuter or not
	unsigned int m_background = 0;
	std::vector<std::string> m_playerName;
	std::vector<sf::Color> m_playersColor;
};

class Menu
{
public:
	Menu();
	bool run(sf::RenderWindow& window);
	Input getInput() { return m_input; };
	sf::Color getColor(int colorNum);
	void setResources(sf::Font& font, sf::Texture& backGround, sf::Texture& headLine,
		std::vector<sf::Texture>& players,
		sf::Texture& playWithFriends, sf::Texture& playWithComputer,
		sf::Texture& backGround1, sf::Texture& backGround2);

private:
	void setHeadLine(const int index, std::string headLine);
	void drawMenu(sf::RenderWindow& window);
	void setPlayerTextField();
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
	Input m_input;
	std::vector<sf::RectangleShape> m_textFields;
	//this index will be the index of the curr group which enter the name of the group
	int m_currGroup = 0;
	int m_groupAmount = 0;
	//for the headlines of menu fields
	std::vector<sf::Text> m_headLines;
	Input m_menuParameters;
	int updatePress(sf::Vector2f location);
	sf::Sprite m_background1;
	sf::Sprite m_background2;
	sf::Sprite m_playWithComp;
	sf::Sprite m_playWithFriend;
	std::vector<sf::Texture> m_MenuTextures;
};
