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
#include "Ground.h"

#define TIMESTEP 1.0f/60.0f     // Refresh time
#define VELITER 10             // Number of iterations per tick to calculate speed
#define POSITER 10              // Number tick iterations to calculate the position

class Player
{
	//using playerVector = std::vector<std::unique_ptr<Player>>;
public:
	Player(std::string name, sf::Color color, int background,std::shared_ptr<b2World> m_world);
	std::string getName() { return m_name; };
	//~Player();
	void run(sf::RenderWindow& window, sf::Event& event, std::vector<std::unique_ptr<Player>>& groupPlayers,
			sf::RectangleShape &featuresMenu, Ground& ground);
	void draw(sf::RenderWindow& window);					//draw all the worms
	void loadFeatures(const sf::Texture& tex, const sf::Vector2f& pos);
	
private:
	void checkClick(sf::Vector2f clickLocation);
	std::shared_ptr<b2World> m_world;
	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::vector < std::unique_ptr<Features>> m_features;
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
	sf::Clock m_wormsTime;
	sf::Clock m_wormsTimeAnimation;
	sf::Clock m_roundTimer;
	sf::Text m_timeForRound;
	
	void chooseWeapon(sf::RenderWindow& window, sf::Event& event, sf::RectangleShape& featuresMenu);				//check if some of weapone choose
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

