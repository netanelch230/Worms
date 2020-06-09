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
}

void Resources::loadFont()
{
	m_messege[0].loadFromFile("herist.otf");
}
