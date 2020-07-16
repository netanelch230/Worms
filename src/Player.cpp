#include "Player.h"
#include <iostream>
#include "MyQueryCallback.h"
//---------------------------------------------
/*the c-tor of player will get the group name of the current player
and the color of the group,
world is the physical world of the player
*/
Player::Player(std::string name, sf::Color color, b2World& world, Board& board, FeatureToolBar& FeatureMenu, sf::RenderWindow& window) :
	m_name(name), m_color(color), m_world(world), m_board(board), m_FeatureMenu(FeatureMenu), m_window(window),
	m_feature(nullptr)
{
	creatWorms();
	loadTimer();
	definArrow();
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
void Player::run(std::vector<std::unique_ptr<Player>>& groupPlayers)
{
	auto event = sf::Event{};
	setCurrentPlayer();
	if (m_die)  // if the worms dosent excist.
		return;
	
	Timer::setTime(timeOfRound);			// set time of player's turn.
	if (m_win)
	{
		Timer::setTime(5);
	}
	checkHealth();
	while (!timesUp() && !m_end) //needs to be change
	{
		checkIfEventOccured(event);
		wormMove();
		restartAnimation();
		drawBoardAndAnimation(groupPlayers);

		if (m_drawWeaponMenu) // in here we'll call the draw weapon menu and in addition we'll handle the click of menu
			chooseWeapon(groupPlayers);
		
	}
	setTurnOfPlayer();
	//setOtherWormsFromTurn(groupPlayers); //stack the turn - why?

}


void Player::handleDie()
{
	for (auto& iter : m_worms)
	{
		if (iter->getLife() <= 0)
		{
			if (iter->getNumOfPicture() != animation_grave3)
			{
				iter->setAnimation({ animation_die, WormDieImageCount, false, 0,sizeOfWorm }, 0.05f);
				m_numOfWorms--;
			}

			if (m_numOfWorms == 0)
			{
				m_die = true;
				break;
			}
		}
	}
}
//------------------before
void Player::setWin()
{
	if (m_win)
	{
		for (auto& i : m_worms)
		{
			if (i->getLife() > 0)
			{
				i->setAnimation({ animation_win, winImageCount , true, 0, sizeOfWinAnimation }, 0.07f);
				i->initializeWormSpriteSetting(sf::Vector2f{ 20,20 }, Resource::instance().getTexture(animation_win));
				i->setSprite(20, 40);
			}
		}
	}
	m_win = true;
	Timer::setTime(5);
}

void Player::setWinGroup()
{
	if(m_numOfWorms>0 && !m_die)
		m_win = true;
}

void Player::setTurnOfPlayer()
{
	m_end = false;
	m_worms[m_currWormPlayer]->setRegularAnimation();
	m_worms[m_currWormPlayer]->setStandOrigin();
}

void Player::setCurrentPlayer()
{
	
	if (m_numOfWorms == 0)
	{
		m_die = true;
		return;
	}
	while (m_numOfWorms > 0)
	{
		m_count++;
		if (m_count >= wormsLimit)
			m_count = initCount;
		if (m_worms[m_count]->getLife() > 0)
			break;
	}
	m_currWormPlayer = m_count;	//randomize the current worm that will play now
	m_arrow.setPosition(m_worms[m_currWormPlayer]->getPosition());
}

/*this function will check if an event has occured from the player and will
summon handleClick function if the player pressed on the right click,
this means the player wants to use a feature from the feature's tool bar.
right after handling this case, it will check if the player pressed on
space click - this means he's wants to exert power and shoot or
throw grenade (one of the options).*/
void Player::checkIfEventOccured(sf::Event& event)
{

	if (m_feature)
	{
		m_feature->runFeature(event, m_window, m_drawFeature,
			*m_worms[m_currWormPlayer].get());
		if (auto i = dynamic_cast<WhiteFlag*>(m_feature.get()) && m_drawFeature==1)
			handleWhiteFlag();
	}

	if (m_window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return;
		}
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (event.key.code == sf::Mouse::Button::Right)
				m_drawWeaponMenu = true; // set to true so we'll draw the weapon menu after the case!
			break;

		}
	}
}


/*this function will draw the board and all the animations
and objects+all the of the physical elements.*/
void Player::drawBoardAndAnimation(std::vector<std::unique_ptr<Player>>& groupPlayers)
{
	m_window.clear();
	m_world.Step(TIMESTEP, VELITER, POSITER);
	m_board.draw(m_window);
	if (m_drawWeaponMenu)
		m_FeatureMenu.drawFeatureMenu(m_window);

	m_window.draw(m_timeForRound);

	for (auto& group : groupPlayers)
	{
		group->update();
		group->draw();
	}

	if (m_feature)
	{
		if (m_drawFeature > 1 && m_drawFeature < 4)
		{
			m_feature->update();
			m_feature->draw(m_window);
		}
		else if (m_feature->destroy(Timer::getTime()) || m_drawFeature==endFeatur)
		{
			m_feature.reset();
			m_worms[m_currWormPlayer]->setRegularAnimation();
			m_worms[m_currWormPlayer]->setStandOrigin();
			m_end = true;
			m_drawFeature = startAnimation;
		}
	}
	m_window.draw(m_arrow);
	m_window.display();
}

/*this function will draw the worms on the board+animations by using polymorphizm
in draw of Worm class.*/
void Player::draw() const
{
	for (auto& i : m_worms)
		i->draw(m_window);
}

void Player::chooseWeapon(std::vector<std::unique_ptr<Player>>& groupPlayers)
{
	while (m_drawWeaponMenu && !timesUp()) // while we still want to use the weapon Menu
	{
		drawBoardAndAnimation(groupPlayers);
		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					m_drawWeaponMenu = false;
					break;   //didn't use menubreak;
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto location = locatin(event); //will return where pressed on board
					checkClick(location);
				}
				m_drawWeaponMenu = false;
				break;
			}
		}
	}
}

/*
This function is handling the player click on the weapons tool bar and will check which feature
the player is asking to use. in addition after getting the feature's type we'll create
the Object for the rellevant feature.
*/
void Player::checkClick(sf::Vector2f clickLocation)
{
	std::vector < std::unique_ptr <Button>>& m_FeatureVec = m_FeatureMenu.getFeatureVec();

	for (int i = 0; i < FeatureAmount; i++)
	{
		if (m_FeatureVec[i]->contains(clickLocation) && !m_feature)
		{
			getFeatureName(i + featureDistance);
			break;
		}
	}
}
//---------------------------------------------
//this function will move the worm according to the player action.''
void Player::wormMove()
{
	m_worms[m_currWormPlayer]->move();
	m_arrow.setPosition(m_worms[m_currWormPlayer]->getPosition() + sf::Vector2f{ -20,-90 });
}

//---------------------------------------------

//this function will convert the location we got on the board to vector 2f
sf::Vector2f Player::locatin(sf::Event& event) const
{
	return m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
}

//---------------------------------------------

//this function will update the animation of each worm in the player's group 
void Player::update()
{
	float time = m_wormsTimeAnimation.restart().asSeconds();
	for (auto& i : m_worms)
		i->update(time);
}

//---------------------------------------------
//this function will return 
bool Player::timesUp()
{
	if (Timer::getTime() != timesUP)
	{
		if (m_roundTimer.getElapsedTime().asSeconds() >= 1.f)
		{
			Timer::decTime();
			m_roundTimer.restart();
			m_timeForRound.setString(std::to_string(Timer::getTime()));
		}
		if (Timer::getTime() == 0)
			return true;
	}
	return false;
}
//---------------------------------------------
int Player::getColorArrow()
{
	if (m_color == sf::Color::Red)
		return redArrow;
	else if (m_color == sf::Color::Blue)
		return blueArrow;
	else if (m_color == sf::Color::Green)
		return greenArrow;
}
//---------------------------------------------
void Player::definArrow()
{
	m_arrow.setTexture(Resource::instance().getTexture(blueArrow));
}
//---------------------------------------------
/*
this function will load the timer of the Player's turn.
time for round will describe the time of the player's turn, current time till
the turn of the player is Over.
*/
void Player::loadTimer()
{
	m_timeForRound.setFont(Resource::instance().getfont(font::name_font));
	m_timeForRound.setColor(sf::Color::Black);
	m_timeForRound.setStyle(sf::Text::Bold);
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
		auto loc = randomLocation(randomWidth, randomHight);
		auto i = std::make_unique<Worm>(loc, m_name, m_color, m_world);
		it.swap(i);
	}
}

//-----------------------------------------------------------------
void Player::handleWhiteFlag()
{
	for (auto& i : m_worms)
	{
		i->setAnimation({ animation_whiteFlag,WormWhiteFlagImageCount, true, 1, sizeOfWhiteFlagWorm }, 0.05f);
		i->initializeWormSpriteSetting(sizeOfWhiteFlag, Resource::instance().getTexture(animation_whiteFlag));
		i->setSprite(20, 40);
	}
	m_drawFeature = 2;
	m_whiteflag = true;
	Timer::setTime(oneRound);
}
//---------------------------------------------
void Player::getFeatureName(int index)
{
	auto wormPosition = m_worms[m_currWormPlayer]->getPosition() + sf::Vector2f{ 0,100 };

	switch (index)
	{
	case animation_whiteFlag:
		m_feature = std::make_unique<WhiteFlag>();
		break;
	case animation_walk:
		m_feature = std::make_unique<Speed>();
		break;
	case animation_grenade:
		m_feature = std::make_unique<Grenade>(m_world, wormPosition);
		break;
	case animation_begin_dinamit:
		m_feature = std::make_unique<Dinamit>(m_world, wormPosition);
		break;
	case animation_skip:
		m_feature = std::make_unique<Pass>();
		break;
	case animaiton_sheep:
		m_feature = std::make_unique<Sheep>(m_world, wormPosition);
		break;
	case animation_stinky:
		m_feature = std::make_unique<Stinky>(m_world, wormPosition);
		break;
	case animation_teleporter:
		m_feature = std::make_unique<Transform>();
		break;
		m_feature = nullptr;
	}
}

void Player::checkHealth()
{
	for (auto& j : m_worms)
		j->checkHealth();
}

void Player::restartAnimation()
{
	if (m_worms[m_currWormPlayer]->stand())
	{
		m_worms[m_currWormPlayer]->setStandOrigin();
		if (m_feature)
			m_worms[m_currWormPlayer]->setAnimation(m_feature->getAnimationSet(), 0.03f);
		else
			m_worms[m_currWormPlayer]->setRegularAnimation();
	}

}

std::string Player::getWinningGroupName()
{
	if (m_worms.size() != empty)
		return m_worms[startIndex]->getGroupName();
}
