#pragma once
#include "timer.h"

int Timer::m_time = 0;

Timer::Timer()
{
	m_text.setFont(font(font::name_font));
	m_text.setColor(sf::Color::Black);
	m_text.setString(std::to_string(m_time));
	m_text.setPosition(50, 650);
	m_text.setCharacterSize(20);
}


