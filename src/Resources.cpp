#include "Resources.h"
#include "Enum.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}


void Resources::loadPicture()
{
	m_picture[menuPic1].loadFromFile("menuBackground1.png");
	m_picture[menuPic2].loadFromFile("menuBackground2.png");
	m_picture[playWithFriendsPic].loadFromFile("PlayWithFriends.png");
	m_picture[playWithComputerPic].loadFromFile("PlayWithComputer.png");
	m_picture[backGround1pic].loadFromFile("jerusalemButton.PNG");
	m_picture[backGround2pic].loadFromFile("desertButton.png");
	m_picture[start].loadFromFile("start.png");
	m_picture[exitGame].loadFromFile("exit.png");

	m_picture[p1].loadFromFile("p1.png");
	m_picture[p2].loadFromFile("p2.png");
	m_picture[p3].loadFromFile("p3.png");
	m_picture[p4].loadFromFile("p4.png");

	
	m_picture[featuresMenu].loadFromFile("featuresMenu.png");

	//load background and board to Jerusalem map
	m_picture[jeruland1].loadFromFile("jeruLand1.png");
	m_picture[daviaTower].loadFromFile("davidTower.png");
	m_picture[jeruBack].loadFromFile("jeruBack.png");
	m_picture[lionGate].loadFromFile("lionGate.png");
	m_picture[westrenWall].loadFromFile("wastrenWall.png");

	//load background and board to Jerusalem map
	m_picture[cactus].loadFromFile("cactus.png");
	m_picture[camel].loadFromFile("camel.png");
	m_picture[desertBack].loadFromFile("desertBack.png");
	m_picture[desertLand3].loadFromFile("desertLand3.png");
	m_picture[desertLand4].loadFromFile("desertLand4.png");
	m_picture[desertLand7].loadFromFile("desertLand7.png");
	m_picture[tent].loadFromFile("tent.png");
	m_picture[waterWall].loadFromFile("waterWall.png");

	//load animations!
	m_picture[animation_worm].loadFromFile("worm.png");
	m_picture[animaiton_sheep].loadFromFile("sheep.png");
	m_picture[animation_begin_dinamit].loadFromFile("dinamitBegin.png");
	m_picture[animation_end_dinamit].loadFromFile("dinamitsof.png");
	m_picture[animation_whiteFlag].loadFromFile("wsurndrd.png");
	m_picture[animation_grenade].loadFromFile("greenGrenade.png");
	m_picture[animation_artilary].loadFromFile("callartilery.png");
	m_picture[animation_teleporter].loadFromFile("mahbet.png");
	m_picture[animation_skip].loadFromFile("pass.png");
	m_picture[animation_die].loadFromFile("wdie.png");
	
	m_picture[grenade].loadFromFile("GRENADE1.png");
	m_picture[stinky].loadFromFile("stinkyWalk.png");
	m_picture[sheep].loadFromFile("sheepWalk.png");
	m_picture[dinamit].loadFromFile("dynamite.png");
	
	m_picture[exGrenade].loadFromFile("exGrenade.png");
	m_picture[exSheep].loadFromFile("exSheep.png");
	m_picture[exStinky].loadFromFile("exStinky.png");
	

	//load menu headlines and start game button
	m_picture[playgameButton].loadFromFile("play.png");
	m_picture[gameFormatHeadline].loadFromFile("gameFormat.png");
	m_picture[gameMapHeadline].loadFromFile("gameMap.png");
	m_picture[playersNamesHeadline].loadFromFile("groupName.png");
	m_picture[groupAmountHeadlines].loadFromFile("playersNum.png");

	//load thhw arrow
	m_picture[greenArrow].loadFromFile("arrowGreen.png");
	m_picture[blueArrow].loadFromFile("arrowBlue.png");
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
	float randPlaceX = (rand() % height) +10;
	float randPlaceY = (rand() % width) + 10;

	return sf::Vector2f{ randPlaceX, randPlaceY };
}