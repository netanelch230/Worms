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
	unsigned int m_background;
	unsigned int m_color;
	std::string m_playerName;
};

class Menu 
{
public:
	Menu();
	void run(sf::Texture& menuScreen, sf::RenderWindow& window);
	void setFont(sf::Font& font);
	Input getInput() { return m_input; };
	sf::Color getColor(int colorNum);

private:
	void intializedefinitions(sf::RenderWindow& window);
	void createTextOptions(std::vector<std::string>& menuOptions);
	void initializeColors();
	void initializeGameFormat(std::string curr, sf::RenderWindow& window);
	sf::Text m_playerText;
	std::string m_playerInput;
	std::vector<sf::RectangleShape> m_groupColors;
	std::vector<sf::RectangleShape> m_gameFormat;
	sf::Sprite m_sprite;
	sf::Text m_headLine;
	// members
	Input m_input;

	
};
