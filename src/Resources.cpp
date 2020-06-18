#include "Resources.h"
#include "Enum.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}


void Resources::loadPicture()
{

	m_picture[menuPic].loadFromFile("menuBackground.jpg");
	m_picture[menuHeadline].loadFromFile("wormsHeadline.png");
	m_picture[playWithFriendsPic].loadFromFile("PlayWithFriends.png");
	m_picture[playWithComputerPic].loadFromFile("PlayWithComputer.png");
	m_picture[backGround1pic].loadFromFile("background5.PNG");
	m_picture[backGround2pic].loadFromFile("background3.png");
	m_picture[start].loadFromFile("start.png");
	m_picture[exitGame].loadFromFile("exit.png");
	
	m_picture[p1].loadFromFile("p1.png");
	m_picture[p2].loadFromFile("p2.png");
	m_picture[p3].loadFromFile("p3.png");
	m_picture[p4].loadFromFile("p4.png");

	m_picture[featuresMenu].loadFromFile("featuresMenu.png");
	m_picture[shelf].loadFromFile("wood.png");
	m_picture[stone].loadFromFile("rocks.png");
	//load animations!
	m_picture[f_worm].loadFromFile("worm.png");
	m_picture[f_sheep].loadFromFile("sheep.png");
	m_picture[f_axe].loadFromFile("axe.png");
	m_picture[f_stinky].loadFromFile("boesh.png");
	m_picture[f_whiteFlag].loadFromFile("whiteFlag.png");
	m_picture[f_grenade].loadFromFile("greenGrenade.png");
	m_picture[f_flick].loadFromFile("flick.png");
	m_picture[f_teleporter].loadFromFile("mahbet.png");
	m_picture[f_skip].loadFromFile("pass.png");
}

void Resources::loadFont()
{
	m_font[menu_font].loadFromFile("herist.otf");
	m_font[name_font].loadFromFile("tahoma.ttf");
}

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1 += v2;
}

sf::Vector2f randomLocation(int height, int width)
{
	//srand(time(NULL));
	float randPlaceX = rand() % height;
	float randPlaceY = rand() % width;

	return sf::Vector2f{ randPlaceX, randPlaceY };
}