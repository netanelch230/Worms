#pragma once
#include"Allinclude.h"

//#include "WhiteFlag.h"
//#include "Transform.h"
//#include "Pass.h"
//#include "Stinky.h";

using animationData = std::pair<int, sf::Vector2u>;

#define TIMESTEP 1.0f/60.0f     // Refresh time
#define VELITER 10             // Number of iterations per tick to calculate speed
#define POSITER 10              // Number tick iterations to calculate the position

class Player
{
public:
	Player(std::string name, sf::Color color, b2World& world, Board& board, 
		FeaturesToolBar& featuresMenu,sf::RenderWindow& window);
	std::string getName() { return m_name; }
	~Player() = default;
	void run(sf::Event& event, 
		std::vector<std::unique_ptr<Player>>& groupPlayers);
	void draw() const;					//draw all the worms
	//void loadFeatures(const sf::Texture& tex, const sf::Vector2f& pos);
	bool isWhiteFlag();

private:
	void setTurnOfPlayer();
	void setCurrentPlayer();
	b2World& m_world;
	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
	sf::Clock m_wormsTime;
	sf::Clock m_wormsTimeAnimation;
	sf::Clock m_roundTimer;
	sf::Text m_timeForRound;
	std::unique_ptr<Features> m_feature;
	Board& m_board;
	FeaturesToolBar &m_featuresMenu;
	sf::RenderWindow& m_window;

	bool m_skipTurn = false;
	bool m_whiteFlag = false;
	bool m_telleporter = false;
	bool m_featureAlive = false;
	bool m_end;
	int m_currWormPlayer = 0;
	sf::Clock m_force; // will handle the force of using weapon - physical element.
	//create object for the enum class so we'll be able to used it in the Player's function 
	sf::Sprite m_arrow;

	void explosion();

	void checkButtonFeaturesMenu(sf::Vector2f &location);
	void moveWeaponeFearures();
	void checkIfEventOccured(sf::Event& event);
	void handleCollision(int wep);
	void handleTeleporter();
	void handleFeatureChoosing();
	void handleWhiteFlag();
	void handleSkip();
	void drawBoardAndAnimation(std::vector<std::unique_ptr<Player>>& groupPlayers);
	bool m_drawWeaponMenu = false; //if pressed right click we'll update to true and we'll print the weapon menu
	bool m_drawfeatur = false;
	void chooseWeapon(std::vector<std::unique_ptr<Player>>& groupPlayers);

	void checkClick(sf::Vector2f clickLocation);
	void getFeaturesName(int index);

	void wormMove();
	void update();
	void loadTimer();
	void creatWorms();
	sf::Vector2f locatin(sf::Event&) const;
	bool timesUp();
	int getColorArrow();
	void definArrow();
	void checkHealth();
		void handleSkipTurn();

	
};

