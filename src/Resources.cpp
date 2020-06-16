#include "Resources.h"
#include "Enum.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}

void Resources::loadPicture()
{
	m_picture[arrbackground].loadFromFile("Background.png");
	m_picture[flik].loadFromFile("firepnch.1.png");
	m_picture[grenade].loadFromFile("grenade.1.png");
	m_picture[pass].loadFromFile("skipgo.2.png");
	m_picture[sheep].loadFromFile("sheep.1.png");
	m_picture[whiteflag].loadFromFile("surender.1.png");
	m_picture[featuresMenu].loadFromFile("featuresMenu.png");
	m_animations[worm].loadFromFile("waccuse.png");
	m_animations[axe].loadFromFile("axe.png");
		
	m_Menupictures[menuPic].loadFromFile("menuBackground.png");
	m_Menupictures[menuHeadline].loadFromFile("wormsHeadline.png");
	m_Menupictures[playWithFriendsPic].loadFromFile("PlayWithFriends.png");
	m_Menupictures[playWithComputerPic].loadFromFile("PlayWithComputer.png");
	m_Menupictures[backGround1pic].loadFromFile("background1.PNG");
	m_Menupictures[backGround2pic].loadFromFile("background2.png");
	m_Menupictures[startPlay].loadFromFile("playgame.png");

	m_playersBottonsTextures[0].loadFromFile("p1.png");
	m_playersBottonsTextures[1].loadFromFile("p2.png");
	m_playersBottonsTextures[2].loadFromFile("p3.png");
	m_playersBottonsTextures[3].loadFromFile("p4.png");

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
