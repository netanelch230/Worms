#include "Resources.h"
#include "Enum.h"

void Resources::loadPicture()
{
	m_picture[arrbackground].loadFromFile("Background.png");
	m_picture[flik].loadFromFile("firepnch.1.png");
	m_picture[grenade].loadFromFile("grenade.1.png");
	m_picture[pass].loadFromFile("skipgo.2.png");
	m_picture[sheep].loadFromFile("sheep.1.png");
	m_picture[whiteflag].loadFromFile("surender.1.png");
	m_animations[worm].loadFromFile("waccuse.png");
		
	m_Menupictures[menuPic].loadFromFile("menuBackground.png");
	m_Menupictures[menuHeadline].loadFromFile("wormsHeadline.png");
	m_Menupictures[playWithFriendsPic].loadFromFile("PlayWithFriends.png");
	m_Menupictures[playWithComputerPic].loadFromFile("PlayWithComputer.png");
	m_Menupictures[backGround1pic].loadFromFile("background1.PNG");
	m_Menupictures[backGround2pic].loadFromFile("background2.png");
	m_Menupictures[statPlay].loadFromFile("playgame.png");

	sf::Texture t;
	t.loadFromFile("p1.png");
	m_playersBottonsTextures.push_back(t);
	t.loadFromFile("p2.png");
	m_playersBottonsTextures.push_back(t);
	t.loadFromFile("p3.png");
	m_playersBottonsTextures.push_back(t);
	t.loadFromFile("p4.png");
	m_playersBottonsTextures.push_back(t);

}

void Resources::loadFont()
{
	m_font[menu_font].loadFromFile("herist.otf");
}
