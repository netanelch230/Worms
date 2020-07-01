#include "Transform.h"

Transform::Transform()
: Features(AnimationSet{ animation_teleporter ,teleporterImageCount ,false,1 })
{
	m_sound.setBuffer(Resources::instance().getMusic(transform));
}