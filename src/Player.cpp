	#include "Player.h"
#include <iostream>
#include "MyQueryCallback.h"

//---------------------------------------------
//========================changes for c-tor
//=========================remove background from here and move it to board class!!!!==========================
//---------------------------------------------
/*the c-tor of player will get the group name of the current player
and the color of the group,
world is the physical world of the player
*/
Player::Player(std::string name, sf::Color color, b2World & world,Board& board, FeaturesToolBar& featuresMenu, sf::RenderWindow &window):
	m_name(name), m_color(color), m_world(world),m_board(board), m_featuresMenu(featuresMenu), m_window(window)
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
void Player::run(sf::Event& event,
	std::vector<std::unique_ptr<Player>>& groupPlayers,
	bool &whiteFlag)
{	
	static int count = 0;
	count++;
	if (count == wormsLimit - 1)
		count = 0;
	m_currWormPlayer = count;	//randomize the current worm that will play now
								// while the turn is not over - keep playing, or while the player didnt picked feature-weapon
	m_arrow.setPosition(m_worms[m_currWormPlayer]->getPosition());
	Timer::setTime(timeOfRound);			// set time of player's turn.
	checkHealth();
	while (!timesUp()) //needs to be change
	{
		checkIfEventOccured(event);
		wormMove();
		drawBoardAndAnimation(groupPlayers);
		moveWeaponeFearures();
		if (m_drawWeaponMenu) // in here we'll call the draw weapon menu and in addition we'll handle the click of menu
			chooseWeapon(groupPlayers);
		for(auto&i:m_worms)
			i->destroy();
		
	}
		m_end = false;
	m_worms[m_currWormPlayer]->setAnimation({ animation_worm, sf::Vector2u{ 1,36 }, true, 1, sizeOfWorm }, 0.05f);
	whiteFlag = m_whiteFlag;

}

void Player::explosion()
{
	if (auto i = dynamic_cast<MovingAttack*>(m_feature.get()))
		i->featureExplosion(m_world);
}

void Player::checkButtonFeaturesMenu(sf::Vector2f& location)
{
	//std::vector < std::unique_ptr <Button> > m_featuresVec = m_featuresMenu.getFeaturesVec();

}

void Player::moveWeaponeFearures()
{
	if (m_feature && m_drawfeatur)
		if (auto i = dynamic_cast<MovingAttack*>(m_feature.get()))
			i->moveWeapone();
}

/*this function will check if an event has occured from the player and will
summon handleClick function if the player pressed on the right click,
this means the player wants to use a feature from the feature's tool bar. 
right after handling this case, it will check if the player pressed on 
space click - this means he's wants to exert power and shoot or 
throw grenade (one of the options).*/
void Player::checkIfEventOccured(sf::Event& event)
{
	if (m_window.pollEvent(event))//wait for event from the player
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
		case sf::Mouse::Button::Right:
			m_drawWeaponMenu = true; // set to true so we'll draw the weapon menu after the case!
			break;
		case sf::Event::Closed:
			m_window.close();
			break;
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				if (m_drawfeatur == false)
				{
					m_drawfeatur = true;
					break;
				}
				else
				{
					explosion();
					m_feature->applyFeatures();
				}
				if (m_skipTurn) // in here we'll need to set the worm animation.
				{
					m_worms[m_currWormPlayer]->setAnimation({ animation_worm, sf::Vector2u{ 1,36 }, true, 1, sizeOfWorm }, 0.05f);
					m_end = true;
					m_skipTurn = false;
				}
				auto time = m_force.getElapsedTime().asSeconds();
				m_drawfeatur = true;
				break;
			}
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
		m_featuresMenu.drawFeaturesMenu(m_window);

	m_window.draw(m_timeForRound);

	for (auto& group : groupPlayers)
	{
		group->update();
		group->draw();
	}
	if (m_feature && m_drawfeatur)
	{	
		m_feature->update();
		m_feature->draw(m_window);

		if (m_feature->destroy(Timer::getTime()))
		{
			m_feature.reset();
			m_drawfeatur = false;
		}

	}
	m_window.draw(m_arrow);
	/*m_arrow.update(0.03);
	m_arrow.draw(window);*/
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
					if (event.mouseButton.button == sf::Event::MouseMoved)
					{
						checkButtonFeaturesMenu(location);
					}
					checkClick(location);
					handleFeatureChoosing();
					//m_worms[m_currWormPlayer]->setAnimation(m_feature->getAnimationSet(), 0.05f);
				}
				m_drawWeaponMenu = false;
				break;
			}
		}
	}	
}

void Player::handleSkipTurn()
{
	//m_worms[m_currWormPlayer]->setAnimation({ animation_worm, sf::Vector2u{ 1,36 }, true, 1, sizeOfWorm }, 0.05f);
	m_end = true;
}
/*this function will check if the player didn't choose a feature from the tool bar
and if he chosed a feature we'll set the animation of the feature (switch from regular
worm to worm with feature)*/
void Player::handleFeatureChoosing()
{
if (m_feature == nullptr)
		return;
	//in any other case we need to set the animation to the feature's choosing.
	m_worms[m_currWormPlayer]->setAnimation(m_feature->getAnimationSet(), 0.05f);
	if (m_feature->getAnimationSet().photo == animation_skip)
	{
		m_skipTurn = true;
		handleSkipTurn();
		//in here we'll want to handle skip turn and to wait for space from the user
	}
	else if (m_feature->getAnimationSet().photo == animation_whiteFlag)
		handleWhiteFlag();

	else if (m_feature->getAnimationSet().photo == animation_teleporter)
		handleTeleporter();
}

/*
This function is handling the player click on the weapons tool bar and will check which feature
the player is asking to use. in addition after getting the feature's type we'll create
the Object for the rellevant feature.
*/
void Player::checkClick(sf::Vector2f clickLocation)
{
	std::vector < std::unique_ptr <Button>> &m_featuresVec = m_featuresMenu.getFeaturesVec();
	
	for (int i = 0; i < featuresAmount; i++)
	{
		if (m_featuresVec[i]->contains(clickLocation))
		{
			getFeaturesName(i+ featureDistance);
			break;
		}
	}
}
//---------------------------------------------
//this function will move the worm according to the player action.''
void Player::wormMove()
{
	float time = m_wormsTime.restart().asSeconds();	
	m_worms[m_currWormPlayer]->move(time);
	m_arrow.setPosition(m_worms[m_currWormPlayer]->getPosition() + sf::Vector2f{ -20,-60 });
}

//---------------------------------------------

//this function will convert the location we got on the board to vector 2f
sf::Vector2f Player::locatin(sf::Event& event) const
{
	return m_window.mapPixelToCoords(
		{ event.mouseButton.x, event.mouseButton.y });
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

//---------------------------------------------
//this function will return 
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
			return true;
	}
	return false;
}

int Player::getColorArrow()
{
	if(m_color==sf::Color::Red)
		return redArrow;
	else if (m_color == sf::Color::Blue)
		return blueArrow;
	else if (m_color == sf::Color::Green)
		return greenArrow;
}	

void Player::definArrow()
{
	//AnimationObject d(spriteSetting{ m_worms[m_currWormPlayer]->getPosition() ,sf::Vector2f{1,1},
	//	Resources::instance().getTexture(getColorArrow()) }, arrowImageCount, m_world, true);
	//m_arrow = d;
	//m_world.DestroyBody(m_arrow.getBody());
	m_arrow.setTexture(Resources::instance().getTexture(blueArrow));
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
		auto loc = randomLocation(WIDTH-10,HEIGHT-10);
		auto i = std::make_unique<Worm>(loc, m_name, m_color, m_world);
		it.swap(i);
	}
}

//-----------------------------------------------------------------

void Player::handleWhiteFlag()
{
	for (auto& i : m_worms)
	{
		i->setAnimation({ animation_whiteFlag, sf::Vector2u{ 1,10 }, true, 1, sizeOfWhiteFlagWorm }, 0.05f);
	}
	m_whiteFlag = true;
	Timer::setTime(oneRound);
}

void Player::handleSkip()
{
	while (m_roundTimer.getElapsedTime().asSeconds() > 1.f)
	{
		if (auto event = sf::Event{}; m_window.pollEvent(event))
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
void Player::handleTeleporter()
{
	while (true)
	{
		//in here we'll wait for mouse button press- so we'll move the worm to the wanted location
		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					b2Vec2 loc{ locatin(event).x * MPP, locatin(event).y * MPP };
					m_worms[m_currWormPlayer]->getBody()->SetTransform(loc, 
						m_worms[m_currWormPlayer]->getBody()->GetAngle());
				}
				break;
			}
		}
	}
}

void Player::getFeaturesName(int index)
{
	auto wormPosition = m_worms[m_currWormPlayer]->getPosition() + sf::Vector2f{ 0,5 };
	
	switch (index)
	{
	case animation_whiteFlag://23
		m_feature = std::make_unique<WhiteFlag>();
		break;
	case animation_artilary:
		m_feature = std::make_unique<Artilary>(m_world, wormPosition);
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