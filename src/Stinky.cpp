#pragma once
#include "Stinky.h"

Stinky:: Stinky(b2World& world, sf::Vector2f position) :
			MovingAttack(world, spriteSetting{ position,{1,1},image(stinky) },
			AnimationSet{ animation_stinky,stinkyImageCount,false,1, sizeOfStinky },
				stinkyAnimationImageCaount,0, { -0.1f ,2.f }, {0.1f ,2.f }) 
{
	m_sound.setBuffer(Music(skunk_walk));
	m_soundGass.setBuffer(Music(skunk_gas));
}
//======================================================
void Stinky::aliveFeature(sf::Event &event, sf::RenderWindow &window, Worm &worm,int& drawFeature)
{
	if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto wormScale = worm.getScale();
				setPosition(worm.getPosition());
				m_body->SetTransform({ worm.getPosition().x * MPP, worm.getPosition().y * MPP },
					m_body->GetAngle());
				m_body->SetAwake(true);
				m_sprite.setScale({ wormScale.x * -1,wormScale.y });
				drawFeature++;
				worm.setRegularAnimation();
			}
		}
}
//======================================================
void Stinky::applyFeature(sf::Event &event,int& drawFeature)
{
	if (m_sound.getStatus() != m_sound.Playing)
		m_sound.play();
		
	/*if (m_soundGass.getStatus() != m_soundGass.Playing)
		m_soundGass.play();*/

	m_body->ApplyForce(force(), m_body->GetWorldCenter(), true);
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				auto world = getBody()->GetWorld();
				featureExplosion(*world);	
				m_soundGass.play();
				setAnimation(AnimationSet{ exStinky,exSkunkImageCount, false }, 0.07f);
				drawFeature++;		
			}
		}
}

void Stinky::attackTakeOfPoints(Worm& worm)
{
	worm.setHelth();
	worm.takeOffPoints(10);
	
}

