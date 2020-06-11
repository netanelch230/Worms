#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "Worm.h"
#include "Enum.h"
#include "Attack.h"
#include <array>

using animArray = std::array<sf::Texture, countOfPicture>;

class Player
{
public:
	Player(std::string name, sf::Vector2f location, sf::Color color,
		animArray animat);
	std::string getName() { return m_name; };
	//~Player();
	void run(sf::RenderWindow& window, sf::Event& event);
	void draw(sf::RenderWindow& window);					//draw all the worms
	void loadFeatures(const sf::Texture& tex, const sf::Vector2f& pos);

	
private:

	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::vector < std::unique_ptr<Features>> m_features;
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
	sf::Clock m_wormsTime;
	animArray m_animat;

	void chooseWeapone(sf::RenderWindow& window, sf::Event& event);				//check if some of weapone choose
	void chooseWorm(sf::RenderWindow& window, sf::Event& event, int& place);	//check if some of worm choose, if not the computer choose one randomalic
	void wormMove(int i);
	sf::Vector2f locatin(sf::RenderWindow&, sf::Event&);
	void update();
};

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2);