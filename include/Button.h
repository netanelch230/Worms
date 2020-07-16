#pragma once
#include <SFML/Graphics.hpp>

//--------------class--------------
class Button
{
public:
	Button(const sf::Sprite& button, const sf::Vector2f& buttonPos);
	sf::Vector2f getButtonPosition() const; //get position of menu button
	void draw(sf::RenderWindow& window) const; //draw the window
	bool contains(const sf::Vector2f& pos) const;	//check if the position of the mouse is on the button
	void moveButton(sf::Vector2f position);//when the user press on button
	void unMoveButton(sf::Vector2f position);//return the button 
	virtual ~Button() = default; //d-tor

private:
	sf::Sprite m_button;
};