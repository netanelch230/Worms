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
	sf::Texture& getMenuTexture(const int& i) { return m_Menupictures[i]; };

	sf::Font& getfont(const int& i) { return m_messege[i]; };
	sf::Music& getMusic(int i);

private:
	std::vector<sf::RectangleShape> m_rectangle;
	std::vector<sf::Texture> m_Menupictures;
	std::vector<sf::Texture> m_playersBottonsTextures;
	std::array<sf::Texture, countOfPicture> m_picture;
	std::array<sf::Font, countOfFont> m_messege;
	std::vector<sf::Font> m_font;
	//std::array<sf::Music,countOfMusic> m_sound;
	void loadPicture();
	void loadFont();
	//void loadSound();
};

