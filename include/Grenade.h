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
	Grenade(b2World& world, sf::Vector2f position) :
		Attack(world, 
			spriteSetting{ position,grenadeSize,Resources::instance().getTexture(grenade) },
			AnimationSet{ animation_grenade,spriteSheetGrenadeSize,false,1 },
			GreenGrenadeImageCount) {
    m_body->SetFixedRotation(false);
}
	virtual void applyFeatures(float time) {
			
		auto pos = m_body->GetWorldCenter();
		if (m_sprite.getScale() == RIGHT)
			m_body->ApplyForce({ 250.f, 250.f }, pos, true);
		else if(m_sprite.getScale() == LEFT)
			m_body->ApplyForce({ -250.f, 250.f }, pos, true);
	};

private:


};