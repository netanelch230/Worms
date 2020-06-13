#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>

class Timer
{
public:
	Timer();
	static void setTime(int time) { m_time = time; };
	static void decTime() { m_time--; };
	static int getTime() { return m_time; }

private:
	static int m_time;
	sf::Text m_text;
};
