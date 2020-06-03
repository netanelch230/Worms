#pragma once
#include "Player.h"
class Controller
{
public:
	
private:
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(1200, 700),
		"Worms");
	sf::Event m_event;
	std::vector<std::unique_ptr<Player>> m_player;
};

