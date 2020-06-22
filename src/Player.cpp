#include "Player.h"
#include <iostream>

//---------------------------------------------
//========================changes for c-tor
//=========================remove background from here and move it to board class!!!!==========================
//---------------------------------------------
/*the c-tor of player will get the group name of the current player
and the color of the group,
world is the physical world of the player
*/
Player::Player(std::string name, sf::Color color, int background, std::shared_ptr<b2World> world) :
	m_name(name), m_color(color), m_world(world)
{
	creatWorms();
	loadTimer();
	restartBackground(backGround1pic);
}


//---------------------------------------------
/*
this function will handle the current Player's turn - in each turn
the player is getting 'time of round time to play'
and in this function we'll run on the worms vector of the current group,
displaying their animation, and in each turn were giving to different worm
of the group the oppurtunity to play by randomizing the current worm
that will play out of the worms vector.
*/
void Player::run(sf::RenderWindow& window,
	sf::Event& event,
	std::vector<std::unique_ptr<Player>>& groupPlayers,
	sf::RectangleShape& featuresMenu,
	staticObjVec& m_staticObject,
	std::vector<sf::Vector2f> featuresLocation)
{
	Timer::setTime(timeOfRound); // set time of player's turn.
	int currWormPlayer = rand() % wormsLimit;//randomize the current worm that will play now
	sf::Clock m_force; // will handle the force of using weapon - physical element.

	// while the turn is not over - keep playing, or while the player didnt picked feature-weapon
	while (!timesUp()) //needs to be change
	{
		if (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
					case sf::Keyboard::Space:
						m_force.restart();
						//in here netanel, karin and yair needs to handle box-2d
						break;
					break;	
				}
			}
			if (sf::Keyboard::isKeyPressed  && ((event.key.code == sf::Keyboard::Space)))
			{
				switch (event.type)
				{
				case::sf::Event::KeyReleased:
					case::sf::Keyboard::Space:
						auto time = m_force.getElapsedTime().asSeconds();
						m_drawfeatur = true;
						m_feature->applyFeatures(time);
					break;
				break;
				}

			}
			if (sf::Mouse::isButtonPressed)
			{
				switch (event.type)
				{
				case sf::Event::MouseButtonPressed:
				case sf::Mouse::Button::Right:
					m_drawWeaponMenu = true;
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
		}
		wormMove(currWormPlayer);
		drawBoardAndAnimation(window, groupPlayers, featuresMenu, m_staticObject);
		if (m_drawWeaponMenu)
				chooseWeapon(window, featuresMenu, featuresLocation, currWormPlayer, groupPlayers,
					m_staticObject);
	}	
	//set current worm to regular worm because turn is over!
	m_worms[currWormPlayer]->setAnimation(Resources::instance().getTexture(animation_worm), wormImageCount, animationSwitchTime,1);
}

void Player::drawBoardAndAnimation(sf::RenderWindow& window, std::vector<std::unique_ptr<Player>>& groupPlayers, sf::RectangleShape& featuresMenu,
	staticObjVec &m_staticObject)
{
	window.clear();
	m_world->Step(TIMESTEP, VELITER, POSITER);
	window.draw(m_background);
	if (m_drawWeaponMenu)
		window.draw(featuresMenu);
	for (auto& i : m_staticObject)
		i->draw(window);

	window.draw(m_timeForRound);

	for (auto& group : groupPlayers)
	{
		group->update();
		group->draw(window);
	}
	if (m_feature && m_drawfeatur)
		m_feature->draw(window);
	window.display();
}
void Player::draw(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
		i->draw(window);
}


void Player::chooseWeapon(sf::RenderWindow& window, sf::RectangleShape& featuresMenu,
	std::vector<sf::Vector2f> featuresLocation, int currWorm,
	std::vector<std::unique_ptr<Player>>& groupPlayers, staticObjVec& m_staticObject)
{
	while (m_drawWeaponMenu && !timesUp()) // while we still want to use the weapon Menu
	{
		drawBoardAndAnimation(window, groupPlayers, featuresMenu, m_staticObject);
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					m_drawWeaponMenu = false;
					break;                               //didn't use menubreak;
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto location = locatin(window, event); //will return where pressed on board
					m_feature = checkClick(location, featuresLocation, currWorm);
					//handleFeatureChoosing(featureToCreate, currWorm, window);
					auto place = m_feature->getPlace();
					auto imageCount = m_feature->getImageCount();
					auto distance = m_feature->getDistance();
					m_worms[currWorm]->setAnimation(Resources::instance().getTexture(place),
						imageCount, 0.05f,distance);
				}
				m_drawWeaponMenu = false;
				break;
			}
		}
	}
}

void Player::handleFeatureChoosing(animationData featureToCreate, int currWorm, sf::RenderWindow& window)
{
	if (featureToCreate.first == -1)
		return;
	m_worms[currWorm]->setAnimation(Resources::instance().getTexture(featureToCreate.first),
		featureToCreate.second, animationSwitchTime,1);
	handleCollision(featureToCreate.first, window);
}

/*
This function is handling the player click on the weapons tool bar and will check which feature
the player is asking to use. in addition after getting the feature's type we'll create 
the Object for the rellevant feature.
*/
std::unique_ptr<Features> Player::checkClick(sf::Vector2f clickLocation,
	std::vector<sf::Vector2f> featuresLocation, int currWorm)
{
	int currLocationModuluRows = 0;
	for (auto i = featuresLocation.begin(); i != featuresLocation.end(); ++i)
	{
		if (abs(clickLocation.x - i->x) < squareSize && abs(clickLocation.y - i->y) < squareSize)
		{
			return getFeaturesName(std::distance(featuresLocation.begin(), i) + featureDistance, currWorm);
		}
	}
	return NULL;
}

void Player::chooseWorm(sf::RenderWindow& window, sf::Event& event, int& place)
{
	auto location = locatin(window, event);
	int j = 0;
	for (auto& i : m_worms)
	{
		if (i->touch(location))
		{
			place = j;
			break;
		}
		j++;
	}
}

void Player::wormMove(int i)
{
	float time = m_wormsTime.restart().asSeconds();
	m_worms[i]->move(time);
}

sf::Vector2f Player::locatin(sf::RenderWindow& window, sf::Event& event)
{
	return window.mapPixelToCoords(
		{ event.mouseButton.x, event.mouseButton.y });
}

void Player::update()
{
	float time = m_wormsTimeAnimation.restart().asSeconds();

	for (auto& i : m_worms)
		i->update(time);
}

void Player::handleCollision(int wep,sf::RenderWindow& window)
{
	switch (wep)
	{
	case animaiton_sheep:
		break;
	case animation_grenade:
		break;
	case animation_flick:
		break;
	case animation_axe:
		//figure the player who werw attacked and change his life to helf
		break;
	case animation_teleporter:
	{
		handleTeleporter(window);
		break;
	}
	case animation_whiteFlag:
		handleWhiteFlag(window);
		//flag to all worms and dissapered
		break;
	case animation_stinky:
		// all worms from other group that in area became sick and lose 5 life any turn
		break;
	case animation_skip:
	{
		handleSkip(window);
		//wait for press and end the section
		break;
	}
	}
}

void Player::handleWhiteFlag(sf::RenderWindow &window)
{
	for (auto& i : m_worms)
	{
		i->setAnimation(Resources::instance().getTexture(animation_whiteFlag), whiteFlagImageCount, 0.03f,1);
	}
}

void Player::handleSkip(sf::RenderWindow & window)
{
	while(m_roundTimer.getElapsedTime().asSeconds() > 1.f)
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed)
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:
				case sf::Keyboard::Space:
					break;
					break;
				}
			}
		}
	}
}


void Player::handleTeleporter(sf::RenderWindow& window)
{
	while (true)
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto location = locatin(window, event); //will return where pressed
					//we need to use box-2d here with the location we got!
				}
				break;
			}
		}
	}
}


bool Player::timesUp()
{
	if (Timer::getTime() != -1)
	{
		if (m_roundTimer.getElapsedTime().asSeconds() >= 1.f)
		{
			Timer::decTime();
			m_roundTimer.restart();
			m_timeForRound.setString(std::to_string(Timer::getTime()));
		}
		if (Timer::getTime() == 0)
		{
			return true;
		}
	}
	return false;
}

/*
this function will load the timer of the Player's turn.
time for round will describe the time of the player's turn, current time till
the turn of the player is Over.
*/
void Player::loadTimer()
{
	m_timeForRound.setFont(Resources::instance().getfont(font::name_font));
	m_timeForRound.setColor(sf::Color::Yellow);
	m_timeForRound.setPosition(timeForRoundPosition);
	m_timeForRound.setCharacterSize(timeForRoundCharacter);
	m_roundTimer.restart();//restart player turn timer
}

//---------------------------------------------
//changes: loc - were doing random Location - must be changed!!!!!!!!!!!!!!!!!!
//---------------------------------------------
/*this function will create the worms of the current player - it's own worms group
in addition, it will define each worm's initial location on the board
and will create Worm object for each worm in the group.
*/
void Player::creatWorms()
{
	m_worms.resize(wormsLimit);
	for (auto& it : m_worms)
	{
		auto loc = randomLocation(HEIGHT, WIDTH);
		auto i = std::make_unique<Worm>(loc, m_name, m_color, *m_world.get());
		it.swap(i);
	}
}

/*
//======================================changes - remover this function
*/
void Player::restartBackground(int i)
{
	m_background.setTexture(&Resources::instance().getTexture(i));
	m_background.setSize({ WIDTH,HEIGHT });

}

//-----------------------------------------------------------------

std::unique_ptr<Features> Player::getFeaturesName(int index, int current)
{
	auto wormPosition = m_worms[current]->getPosition();
	std::unique_ptr<Features> p;
	
	switch (index)
	{
	case animaiton_sheep:
		p = std::make_unique<Sheep>(*m_world.get(), wormPosition);
		break;
	case animation_grenade:
		p = std::make_unique<Grenade>(*m_world.get(), wormPosition);
		break;
	case animation_flick:
		p = std::make_unique<Flick>(*m_world.get(), wormPosition);
		break;
	case animation_axe:
		p = std::make_unique<Axe>(*m_world.get(), wormPosition);
		break;
	case animation_teleporter:
		p = std::make_unique<Transform>();
		break;
	case animation_whiteFlag:
		p = std::make_unique<WhiteFlag>();
		break;
	case animation_stinky:
		p = std::make_unique<Stinky>(*m_world.get(), wormPosition);
		break;
	case animation_skip:
		p = std::make_unique<Pass>();
		break;

	}
	return p;
	
}