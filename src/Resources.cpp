#include "Resources.h"
#include "Enum.h"

void Resources::loadPicture()
{
	sf::Texture t;
	t.loadFromFile("menuBackground.png");
	m_pictures.push_back(t);
	t.loadFromFile("wormsHeadline.png");
	m_pictures.push_back(t);
	t.loadFromFile("p1.png");
	m_playersTextures.push_back(t);
	t.loadFromFile("p2.png");
	m_playersTextures.push_back(t);
	t.loadFromFile("p3.png");
	m_playersTextures.push_back(t);
	t.loadFromFile("p4.png");
	m_playersTextures.push_back(t);
}

void Resources::loadFont()
{
	sf::Font f;
	f.loadFromFile("herist.otf");
	m_font.push_back(f);
}
