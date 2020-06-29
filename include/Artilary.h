#pragma once
#include"NonMovingAttack.h"
#include"Enum.h"


class Artilary :public NonMovingAttack {
public:
	Artilary(b2World& world, sf::Vector2f position) :
		NonMovingAttack(world,
			spriteSetting{ position,sf::Vector2f{20,20},Resources::instance().getTexture(artileri) },
			AnimationSet{ animation_artilary,callartilary,false,1 },
			artilaryimagecount) {}
	virtual void applyFeatures();
	virtual void play() override {};
};


