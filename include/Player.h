#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "Worm.h"
#include "Enum.h"
#include "Attack.h"
#include "Resources.h"
#include "Timer.h"
#include "Grenade.h"
#include "Sheep.h"
#include "Flik.h"
#include "Axe.h"
#include "Stinky.h"
#include "Transform.h"
#include "WhiteFlag.h"
#include "Pass.h"


#include "staticObject.h"
//#include "WhiteFlag.h"
//#include "Transform.h"
//#include "Pass.h"
//#include "Stinky.h";

;
using staticObjVec = std::vector<std::unique_ptr<staticObject>>;
using animationData = std::pair<int, sf::Vector2u>;

#define TIMESTEP 1.0f/60.0f     // Refresh time
#define VELITER 10             // Number of iterations per tick to calculate speed
#define POSITER 10              // Number tick iterations to calculate the position

class Player
{
	//using playerVector = std::vector<std::unique_ptr<Player>>;
public:
	Player(std::string name, sf::Color color, int background, std::shared_ptr<b2World> m_world);
	std::string getName() { return m_name; }
	//~Player();
	void run(sf::RenderWindow& window, sf::Event& event, 
		std::vector<std::unique_ptr<Player>>& groupPlayers,
			sf::RectangleShape &featuresMenu, staticObjVec& m_staticObject,
		std::vector<sf::Vector2f> featuresLocation);
	void draw(sf::RenderWindow& window);					//draw all the worms
	//void loadFeatures(const sf::Texture& tex, const sf::Vector2f& pos);
	
private:

	std::shared_ptr<b2World> m_world;
	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
	sf::Clock m_wormsTime;
	sf::Clock m_wormsTimeAnimation;
	sf::Clock m_roundTimer;
	sf::Text m_timeForRound;
	std::unique_ptr<Features> m_feature;
	
	void handleCollision(int wep, sf::RenderWindow& window);
	void handleTeleporter(sf::RenderWindow& window);
	void handleFeatureChoosing(animationData featureToCreate, int currWorm, sf::RenderWindow& window);
	void handleWhiteFlag(sf::RenderWindow& window);
	void handleSkip(sf::RenderWindow & window);

	void drawBoardAndAnimation(sf::RenderWindow& window, std::vector<std::unique_ptr<Player>>& groupPlayers, sf::RectangleShape& featuresMenu,
		staticObjVec& m_staticObject);
	bool m_drawWeaponMenu = false; //if pressed right click we'll update to true and we'll print the weapon menu
	bool m_drawfeatur = false;
	void chooseWeapon(sf::RenderWindow& window, sf::RectangleShape& featuresMenu,
		std::vector<sf::Vector2f> featuresLocation, int currWorm,
		std::vector<std::unique_ptr<Player>>& groupPlayers, staticObjVec& m_staticObject);

	std::unique_ptr<Features> checkClick(sf::Vector2f clickLocation, std::vector<sf::Vector2f> featuresLocation, int currWorm);
	std::unique_ptr<Features> getFeaturesName(int index, int current);

	void chooseWorm(sf::RenderWindow& window, sf::Event& event, int& place);	//check if some of worm choose, if not the computer choose one randomalic
	void wormMove(int i);
	void update();
	void loadTimer();
	void creatWorms();
	void restartBackground(int i);
	sf::Vector2f locatin(sf::RenderWindow&, sf::Event&);
	bool timesUp();
	sf::RectangleShape m_background;

	//create object for the enum class so we'll be able to used it in the Player's function 
	
};

