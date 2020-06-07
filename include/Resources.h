#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"

enum e_music
{
	gamemusic,
	deathmusic,
	diamondmusic
};
class Resources
{
public:
	Resources() {
		loadPicture();
		loadFont();
	};
	~Resources() = default;
	void loadPicture();
	void loadFont();
	void loadSound();
	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Font& getfont(const int& i) { return m_messege[i]; };
	//sf::Music& getMusic(int i);

private:
	std::vector<sf::RectangleShape> m_rectangle;
	sf::Texture m_picture[16];
	sf::Font m_messege[5];
	//sf::Music m_sound[3];
};

