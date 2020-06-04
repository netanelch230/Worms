#pragma once
#include <SFML/Graphics.hpp>
#include <Resources.h>
#include "Player.h"
#include "Menu.h"
class Controller
{
public:
	Controller();
	~Controller() {};
	void run();                   //main function
	void menu();
	
private:
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	std::vector<std::unique_ptr<Player>> m_player;
	sf::Event m_event;
	Resources m_resources;
	Menu m_menu;
	sf::RectangleShape m_background;
	void restartPlayers();
	void restartBackground();
	
};

