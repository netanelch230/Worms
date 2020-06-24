#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include"Enum.h"
#include "GameMenu.h"
#include "Board.h"
#include "MyContactListener.h"

class Controller
{
public:
	Controller();
	~Controller() {};
	void run();                   //main function
	
private:
	
	std::unique_ptr <b2World> m_world;
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	sf::RectangleShape m_featuresMenu;
	std::vector<sf::Vector2f> m_featuresLocation;
	std::vector<std::unique_ptr<Player>> m_player;
	sf::Event m_event;
	GameMenu m_menu;
	Board m_board;
	MyContactListener m_contactListener;

	void restartFeaturesMenu();
	void restartPlayers();        //build the player from menuInput
	void defineBoard();     //define the arrbackground from menuInput
	void drawPlayer();
	void exitGame();
	void restartFeaturesLocation();
};


