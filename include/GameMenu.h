#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Resources.h"
#include "Enum.h"
#include <string>
#include "Button.h"

//for user's input:
struct Input
{
	unsigned int m_numOfPlayers;
	bool m_gameFormat = true;			 // with copmuter or not
	unsigned int m_background = backGround1pic;
	std::vector<std::string> m_playerName;
	std::vector<sf::Color> m_playersColor;
};

class GameMenu
{
public:

	GameMenu();
	bool run(sf::RenderWindow& window);
	sf::Color getColor(int colorNum) const;
	Input getInput() { return m_menuParameters; }
	~GameMenu() = default;

private:

	bool optionsEvents(sf::RenderWindow& window);
	bool updatePress(sf::Vector2f location);
	bool checkEvent(sf::RenderWindow& window);
	void drawFirstMenu(sf::RenderWindow& window) const;
	void drawSecondMenu(sf::RenderWindow& window) const;
	void buildButtons();
	void setPlayerTextField();
	sf::RectangleShape createRectangleShape(int row) const;
	void setTextFieldsHeadlines();
	void setHeadLine(const int index, std::string headLine);
	void initializeColors();
	void setResources();
	void setMenuParameters();

	int m_groupAmount = 0;
	int m_currGroup = 0;
	bool m_startGame = false;

	std::vector<sf::Text> m_playerText;
	std::vector<sf::String> m_playerInput;

	std::vector<sf::RectangleShape> m_textFields;
	sf::Sprite m_spriteHeadline;
	std::vector<sf::Text> m_headLines;

	std::vector<sf::RectangleShape> m_groupColors;
	std::vector<sf::RectangleShape> m_gameFormat;
	std::vector<sf::RectangleShape> m_background;

	sf::Sprite m_spriteBackgraound1;
	sf::Sprite m_spriteBackgraound2;
	sf::Sprite m_spritePlay;
	sf::Sprite m_spriteExit;
	sf::Sprite m_spriteComp;
	sf::Sprite m_spriteFriend;
	sf::Sprite m_spriteMap1;
	sf::Sprite m_spriteMap2;
	sf::Sprite m_playGame;
	std::vector<sf::Sprite> m_playersSprite;
	std::vector<sf::Sprite> m_hedlinesSprite;

	std::unique_ptr<Button> m_playButton;	// play button
	std::unique_ptr<Button> m_exitButton;	// exit button
	std::unique_ptr<Button> m_playWithComp;
	std::unique_ptr<Button> m_playWithFriend;
	std::unique_ptr<Button> m_map1;
	std::unique_ptr<Button> m_map2;
	std::unique_ptr<Button> m_playGameButton;
	std::vector < std::unique_ptr <Button>> m_playersButtons;

	Input m_menuParameters;

};