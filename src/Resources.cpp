#include "Resources.h"
#include "Enum.h"
void Resources::loadPicture()
{
<<<<<<< karin
	m_picture[menuPic].loadFromFile("menuBackground.png");
=======
	m_picture[arrbackground].loadFromFile("Background5.png");
	m_picture[flik].loadFromFile("firepnch.1.png");
	m_picture[grenade].loadFromFile("grenade.1.png");
	m_picture[pass].loadFromFile("skipgo.2.png");
	m_picture[sheep].loadFromFile("sheep.1.png");
	m_picture[whiteflag].loadFromFile("surender.1.png");
	m_picture[featuresMenu].loadFromFile("featuresMenu.png");

	m_animations[worm].loadFromFile("worm.jpg");

	m_picture[shelf].loadFromFile("wood.png");
	m_picture[stone].loadFromFile("stone.jpg");
	m_animations[worm].loadFromFile("worm.png");

	m_animations[axe].loadFromFile("axe.png");
		
	m_Menupictures[menuPic].loadFromFile("menuBackground.jpg");
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

>>>>>>> local
}

void Resources::loadFont()
{
	m_messege[0].loadFromFile("herist.otf");
}
