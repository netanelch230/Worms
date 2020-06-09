#include "Worm.h"

bool Worm::touch(sf::Vector2f location)
{
    return m_sprite.getGlobalBounds().contains(location);
}
