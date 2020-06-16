#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "Menu.h"
#include"Enum.h"

class Controller
{
public:
	Controller();
	~Controller() {};
	void run();                   //main function
	
private:
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	std::vector<std::unique_ptr<Player>> m_player;
	sf::Event m_event;
	Menu m_menu;
	sf::RectangleShape m_background;

	void restartPlayers();        //build the player from menuInput
	void restartBackground();     //define the arrbackground from menuInput
	void drawPlayer();
	void exitGame();
};


