#include "Resources.h"
#include "Enum.h"

void Resources::loadPicture()
{
	m_picture[menuPic].loadFromFile("menuBackground.png");
	m_picture[flik].loadFromFile("firepnch.1.png");
	m_picture[grenade].loadFromFile("grenade.1.png");
	m_picture[pass].loadFromFile("skipgo.2.png");
	m_picture[sheep].loadFromFile("sheep.1.png");
	m_picture[whiteflag].loadFromFile("surender.1.png");

	sf::Texture t;
	t.loadFromFile("menuBackground.png");
	m_Menupictures.push_back(t);
	t.loadFromFile("wormsHeadline.png");
	m_Menupictures.push_back(t);
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
	sf::Font f;
	f.loadFromFile("herist.otf");
	m_font.push_back(f);}
