#include "AbsObject.h"

AbsObject::AbsObject(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void AbsObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool AbsObject::touch(sf::Vector2f location)
{
	return m_sprite.getGlobalBounds().contains(location);
}
