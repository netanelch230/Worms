#include "Resources.h"
#include "Enum.h"
void Resources::loadPicture()
{
	m_picture[menuPic].loadFromFile("menuBackground.png");
}

void Resources::loadFont()
{
	m_messege[0].loadFromFile("herist.otf");
}
