#include "AbsObject.h"

AbsObject::AbsObject(const spriteSetting& sset)
{
	m_sprite.setPosition(sset.position);
	m_sprite.setTexture(&sset.picture);
	m_sprite.setSize(sset.size);
}

void AbsObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

bool AbsObject::touch(sf::Vector2f location)
{
	return m_sprite.getGlobalBounds().contains(location);
}
