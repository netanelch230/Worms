#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"
#include <array>

class Resources
{
public:
	Resources() {
		loadPicture();
		loadFont();
	};
	~Resources() = default;
	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Font& getfont(const int& i) { return m_messege[i]; };
	sf::Music& getMusic(int i);

private:
	
	std::array<sf::Texture, countOfPicture> m_picture;
	std::array<sf::Font, countOfFont> m_messege;
	//std::array<sf::Music,countOfMusic> m_sound;
	
	void loadPicture();
	void loadFont();
	//void loadSound();
};

