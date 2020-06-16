#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "Worm.h"
#include "Enum.h"
#include "Attack.h"
#include"Resources.h"
#include "Timer.h"

class Player
{
public:
	Player(std::string name, sf::Color color, int background);
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
	sf::Clock m_wormsTimeAnimation;
	sf::Clock m_roundTimer;
	sf::Text m_timeForRound;
	
	void chooseWeapone(sf::RenderWindow& window, sf::Event& event);				//check if some of weapone choose
	void chooseWorm(sf::RenderWindow& window, sf::Event& event, int& place);	//check if some of worm choose, if not the computer choose one randomalic
	void wormMove(int i);
	void update();
	void loadTimer();
	void creatWorms();
	void restartBackground(int i);
	sf::Vector2f locatin(sf::RenderWindow&, sf::Event&);
	sf::Vector2f randomLocation();
	bool timesUp();
	sf::RectangleShape m_background;
};

