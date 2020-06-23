#pragma once
#include "Button.h"

//---------------------------------------------
//c-tor of button class
Button::Button(const sf::Sprite& button, const sf::Vector2f& buttonPos)
{
	m_button = button;
	m_button.setPosition(buttonPos); //set the button place on the window
}

//---------------------------------------------
//get the position of the button
sf::Vector2f Button::getButtonPosition() const
{
	return m_button.getPosition();
}
//---------------------------------------------
//draw the button and text on it
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_button);	// draw button
}
//---------------------------------------------
//check if the position of the mouse is on the button
bool Button::contains(const sf::Vector2f& position) const
{
	return m_button.getGlobalBounds().contains(position);
}
//---------------------------------------------
void Button::moveButton(sf::Vector2f position)
{
	m_button.setColor(sf::Color(255, 255, 255, 127));
	m_button.setPosition(position.x, position.y + 5);
}
//---------------------------------------------
void Button::unMoveButton(sf::Vector2f position)
{
	m_button.setColor(sf::Color::White);
	m_button.setPosition(position);
}
//---------------------------------------------

