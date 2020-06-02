#pragma once
#include "all_include.h"


class Controller
{
public:
	Controller();
	~Controller() {};
	void run();                   //main function
	void insertToToolbar();        
	void printToolbar(); 
	void creatLevel();
	void printLevel();
	void touchOtherObject();		//colission check
	void movingObject();
	void closeWindow();              //close button
	void loadScreen();             
	bool StartOrEnd();               //start game or exit game
	void endGameSuccess();           //finish with success
	void secondPass();               //timer
	void restartOrNewLevel();        //create present level||new level
	sf::Vector2f sizeOfObject();     //calculate the size of objects according to border
	void continueOrEndGame();        //continue the game according to rules     
	void playMusic(int i);
	void nextLevel();
	void endGameFailure();           //life is over
	void restartGame();              //load game from first level
	void deletefromvector();

private:
	Board m_board;
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(1200, 700),
		"DIGGER-GAME");
	sf::Event m_event;
	std::vector<Moving*> m_moving;
	std::vector<std::vector<Non_moving*>> m_nonmoving;
	std::vector<Toolbar*> m_toolbar;
	Recorces m_recorces;
	sf::Clock m_digger_clock;
	sf::Clock m_game_clock;
	int locDig;
	sf::Vector2f m_border;
	std::vector<Screen*> m_screen;
	
};

