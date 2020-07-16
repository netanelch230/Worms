#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Resource.h"
#include "Enum.h"
#include <string>
#include "Button.h"

//for user's input:
struct Input
{
	unsigned int m_numOfPlayers;
	unsigned int m_background = jeruBack;
	std::vector<std::string> m_playerName ;
	std::vector<sf::Color> m_playersColor;
};

//--------------class--------------
class GameMenu
{
public:

	GameMenu();
	bool run(sf::RenderWindow& window);
	sf::Color getColor(int colorNum) const;
	Input getInput() { return m_menuParameters; }
	~GameMenu() = default;

private:
	void setMusic();
	void setPlayerTextFeature();
	void handleKeyPressedEvenet(sf::Event& event);
	void handlePlayersAmountClick(sf::Vector2f location);
	void handleMouseMovedEvent(sf::RenderWindow& window, sf::Vector2f mousePos, sf::Event &event);
	bool optionsEvents(sf::RenderWindow& window);
	bool updatePress(sf::Vector2f location);
	bool checkEvent(sf::RenderWindow& window);
	void drawFirstMenu(sf::RenderWindow& window) const;
	void drawSecondMenu(sf::RenderWindow& window) const;
	void buildButtons();
	void setPlayerTextField();
	sf::RectangleShape createRectangleShape(int row) const;
	void initializeColors();
	void setResources();
	void setMenuParameters();
	void checkTextFieldClick(sf::Vector2f location);
	void openHelpText(sf::RenderWindow& window);
	void closeHelpText(sf::RenderWindow& window);
	bool secondMenuMouseButtonPressed(sf::RenderWindow& window, sf::Event& event);
	void secondMenuMouseButtonMoved(sf::RenderWindow& window, sf::Event& event);
	int m_groupAmount = 0; // this variable will handle the amount of groups we currently have
	int m_currGroup = 0; //this variable will handle the current text field of the current group
	int m_currentGroupAmount = 0;
	bool m_textFieldPressed = false; // we'll set this variable to true if player pressed on text field
	bool m_startGame = false;
	bool m_openHelp = false;

	bool handleSecondMenu(sf::RenderWindow& window);
	std::vector<sf::Text> m_playerText;
	std::vector<sf::String> m_playerInput;

	std::vector<sf::RectangleShape> m_textFields;
	sf::Sprite m_spriteHeadline;
	std::vector<sf::Text> m_headLines;

	std::vector<sf::RectangleShape> m_groupColors;
	std::vector<sf::RectangleShape> m_background;

	sf::Sprite m_spriteBackgraound1;
	sf::Sprite m_spriteBackgraound2;
	sf::Sprite m_spritePlay;
	sf::Sprite m_spriteExit;
	sf::Sprite m_spriteMap1;
	sf::Sprite m_spriteMap2;
	sf::Sprite m_playGame;
	sf::Sprite m_helpButtonSprite;
	sf::Sprite m_helpBackgraound;
	std::vector<sf::Sprite> m_playersSprite;
	std::vector<sf::Sprite> m_hedlinesSprite;

	std::unique_ptr<Button> m_playButton;	// play button
	std::unique_ptr<Button> m_exitButton;	// exit button
	std::unique_ptr<Button> m_map1;
	std::unique_ptr<Button> m_map2;
	std::unique_ptr<Button> m_playGameButton;
	std::unique_ptr<Button> m_helpButton;;
	
	std::vector < std::unique_ptr <Button>> m_playersButtons;
	Input m_menuParameters;

	sf::Sound m_clickSound;
	sf::Sound m_openSong;

};