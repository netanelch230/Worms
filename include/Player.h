#pragma once
#include"Allinclude.h"



#define TIMESTEP 1.0f/60.0f     // Refresh time
#define VELITER 10             // Number of iterations per tick to calculate speed
#define POSITER 10              // Number tick iterations to calculate the position

//----------class-----------
class Player
{
public:
	Player(std::string name, sf::Color color, b2World& world, Board& board, 
		FeatureToolBar& FeatureMenu,sf::RenderWindow& window);
	std::string getName() { return m_name; }
	void run(std::vector<std::unique_ptr<Player>>& groupPlayers);
	void setTurnOfPlayer();
	void draw() const;					//draw all the worms
	//void loadFeature(const sf::Texture& tex, const sf::Vector2f& pos);
	void setWinGroup();
	std::string getWinningGroupName();
	bool getDie() { return m_die; }
	void handleDie();
	void setWin();
	~Player()= default;
	bool getwhiteflag() { return m_whiteflag; };

private:

	b2World& m_world;
	std::vector<std::unique_ptr<Worm>> m_worms; // initialize the size of the vector
	std::string m_name; // will be read from sfml
	sf::Vector2f m_location;
	sf::Color m_color;
	sf::Clock m_wormsTime;
	sf::Clock m_wormsTimeAnimation;
	sf::Clock m_roundTimer;
	sf::Text m_timeForRound;
	std::unique_ptr<Feature> m_feature;
	Board& m_board;
	FeatureToolBar &m_FeatureMenu;
	sf::RenderWindow& m_window;

	bool m_win = false;
	bool m_die=false;
	int m_featureAlive = -1;
	bool m_end;
	int m_currWormPlayer = 0;
	sf::Clock m_force; // will handle the force of using weapon - physical element.
	//create object for the enum class so we'll be able to used it in the Player's function 
	sf::Sprite m_arrow;
	int m_numOfWorms = wormsLimit;
	int m_count = initCount;
	void setCurrentPlayer();
	void checkIfEventOccured(sf::Event& event);
	void handleWhiteFlag();
	void drawBoardAndAnimation(std::vector<std::unique_ptr<Player>>& groupPlayers);
	bool m_drawWeaponMenu = false; //if pressed right click we'll update to true and we'll print the weapon menu
	int m_drawFeature = startAnimation;
	void chooseWeapon(std::vector<std::unique_ptr<Player>>& groupPlayers);
	void checkClick(sf::Vector2f clickLocation);
	void getFeatureName(int index);

	void wormMove();
	void update();
	void loadTimer();
	void creatWorms();
	sf::Vector2f locatin(sf::Event&) const;
	bool timesUp();
	int getColorArrow();
	void definArrow();
	void checkHealth();
	void restartAnimation();
	bool m_whiteflag = false;
};

