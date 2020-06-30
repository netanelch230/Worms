#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <SFML/Audio.hpp>


using picsArray = std::array<sf::Texture, amuntOfPicture>;

class Resources
{
public:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	static Resources& instance();
	~Resources() = default;

	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	sf::SoundBuffer& getMusic(int i) { return m_sound[i]; }

private:
	Resources() {
		loadPicture();
		loadFont();
		loadSound();
	};
	picsArray m_picture;
	sf::Texture m_featuresMenu;
	std::array<sf::Font, countOfFont> m_font;
	std::array<sf::SoundBuffer,countOfMusic> m_sound;
	void loadPicture();
	void loadFont();
	void loadSound();
};

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f randomLocation(int height, int width);

