#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include"Enum.h"
#include"Shelf.h"
#include "GameMenu.h"


class Controller
{
public:
	Controller();
	~Controller() {};
	void run();                   //main function
	
private:
	
	std::shared_ptr<b2World> m_world;
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	sf::RectangleShape m_featuresMenu;
	std::vector<sf::Vector2f> m_featuresLocation;
	std::vector<std::unique_ptr<Player>> m_player;
	staticObjVec m_staticObject;
	sf::Event m_event;
	GameMenu m_menu;
	sf::RectangleShape m_background;
	void restartFeaturesMenu();
	void restartPlayers();        //build the player from menuInput
	void restartBackground();     //define the arrbackground from menuInput
	void defineShelf();
	void defineStatic();
	void defineStone();
	void drawPlayer();
	void exitGame();
	void restartFeaturesLocation();
};


