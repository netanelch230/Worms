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

//----------class-----------
class Resource
{
public:
	Resource(const Resource&) = delete;
	Resource& operator=(const Resource&) = delete;
	static Resource& instance();
	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	sf::SoundBuffer& getMusic(int i) { return m_sound[i]; }
	sf::SoundBuffer& getSong(int i) { return m_music[i]; }
	~Resource() = default;

private:
	Resource() {
		loadPicture();
		loadFont();
		loadSound();
		loadMusic();
	};

	picsArray m_picture;
	sf::Texture m_FeatureMenu;
	std::array<sf::Font, countOfFont> m_font;
	std::array<sf::SoundBuffer,countOfMusic> m_sound;
	std::array<sf::SoundBuffer, songCount> m_music;
	void loadPicture();
	void loadFont();
	void loadSound();
	void loadMusic();

};

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f randomLocation(int height, int width);

sf::Texture& image(int i);
sf::Font& font(int i);
sf::SoundBuffer& Music(int i);
sf::SoundBuffer& song(int i);