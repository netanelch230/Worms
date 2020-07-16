#pragma once
#include "Resource.h"
#include <SFML/Graphics.hpp>

//------------class-----------
class Timer
{
public:
	Timer();
	static void setTime(int time) { m_time = time; };
	static void decTime() { m_time--; };
	static int getTime() { return m_time; }
	virtual ~Timer() = default;

private:
	static int m_time;
	sf::Text m_text;
};
