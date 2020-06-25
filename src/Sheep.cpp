#pragma once
#include "Sheep.h"
#include "..\include\Sheep.h"

void Sheep::applyFeatures(float time)
{
	if (m_sprite.getScale() == LEFT)
		force(left);
	else if (m_sprite.getScale() == RIGHT)
		force(right);
}

void Sheep::changeDirection()
{

	if (m_sprite.getScale() == LEFT)
		m_sprite.setScale(RIGHT);
	else if (m_sprite.getScale() == RIGHT)
		m_sprite.setScale(LEFT);
}
