#pragma once
#include"Attack.h"
#include"Resources.h"

//--------------const-------------------
const auto grenadeSize = sf::Vector2f{ 20, 20 };
const auto spriteSheetGrenadeSize = sf::Vector2u{ 1, 32 };

//-------------class-------------------
class Grenade :public Attack 
{
public:
	Grenade(b2World& world, sf::Vector2f position) :Attack(world, spriteSetting{ position,
	grenadeSize,Resources::instance().getTexture(grenade) },
 spriteSheetGrenadeSize,GreenGrenadeImageCount,animation_grenade) {
    m_body->SetFixedRotation(false);
}
	virtual void applyFeatures(float time) {
			
		auto pos = m_body->GetPosition();
		if (m_sprite.getScale() == RIGHT)
			m_body->ApplyLinearImpulse({ 15.f, 1.f*time*2 }, {pos.x, pos.y }, true);
		else if(m_sprite.getScale() == LEFT)
			m_body->ApplyLinearImpulse({ -15.f, 1.f*time*2 }, {pos.x, pos.y }, true);
	};

private:


};