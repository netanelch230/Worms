#include <SFML/Graphics.hpp>
#include "Resource.h"
#include "Player.h"
#include"Enum.h"
#include "GameMenu.h"
#include "Board.h"
#include "MyContactListener.h"
#include "FeaturesToolBar.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

//--------------class--------------
class Controller
{
public:
	Controller();
	void run(); //function that will run the player
	~Controller() = default;
	
private:
	
	std::unique_ptr <b2World> m_world;
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Worms");
	std::vector<std::unique_ptr<Player>> m_players;
	//sf::Event m_event;
	GameMenu m_menu;
	Board m_board;
	MyContactListener m_contactListener;
	sf::Sprite m_endGame;
	sf::Sound m_startRound;
	FeatureToolBar m_FeatureToolBar;
	int m_numOfPlayers;
	void handleWin();
	void restartPlayers();        //build the player from menuInput
	void defineBoard();     //define the arrbackground from menuInput
	void drawPlayer();
	void displayWinningGroup();
	
	void exitGame();
};

