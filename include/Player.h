#pragma once
#include <vector>
#include <memory>
#include <string>
#include"Worm.h"
#include "Enum.h"
#include <SFML/Graphics.hpp>
#include "Attack.h"

class Player
{
public:
	Player(std::string name, sf::Vector2f location, sf::Color color);
	std::string getName() { return m_name; };
	//~Player();
	void run(sf::RenderWindow& window, sf::Event& event);
private:
	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::vector < std::unique_ptr<Attack>> m_weapons;
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
};
