#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Enum.h"
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using animArray = std::array<sf::Texture, countOfPicture>;

template<int i>
class Texturearray {

public:
	std::array<sf::Texture, i> m_array;
	sf::Texture& operator[](int i) { return m_array[i]; };
	int size() { return m_array.size(); };
};

class Resources
{
public:
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	static Resources& instance();
	~Resources() = default;
	sf::Texture& getTexture(const int& i) { return m_picture[i]; };
	sf::Texture& getMenuTexture(const int& i) { return m_Menupictures[i]; };
	sf::Texture& getAnimations(int i) { return m_animations.m_array[i]; };
	sf::Font& getfont(const int& i) { return m_font[i]; };
	//sf::Music& getMusic(int i);
	sf::Texture& getPlayersTextures(int i) { return m_playersBottonsTextures.m_array[i]; }
	sf::Texture& getFeaturesTexture() { return m_featuresMenu; }
	int sizeOfPlayers() {return m_playersBottonsTextures.size();	}
	Texturearray<10> menupicture();
private:
	Resources() {
		loadPicture();
		loadFont();
	};
	Texturearray<10> m_Menupictures;
	Texturearray<10> m_playersBottonsTextures;
	Texturearray<countOfPicture> m_picture;
	Texturearray<countOfPicture> m_animations;
	sf::Texture m_featuresMenu;
	std::array<sf::Font, countOfFont> m_font;
	//std::array<sf::Music,countOfMusic> m_sound;
	void loadPicture();
	void loadFont();
	//void loadSound();
};

sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2);
sf::Vector2f randomLocation(int height, int width);

