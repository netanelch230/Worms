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
Player::Player(std::string name, sf::Color color, std::shared_ptr<b2World> world,std::shared_ptr<Board> board) :
	m_name(name), m_color(color), m_world(world),m_board(board)
{
	creatWorms();
	loadTimer();
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
	std::vector<sf::Vector2f> featuresLocation)
{	
	Timer::setTime(timeOfRound);			// set time of player's turn.
	m_currWormPlayer = rand() % wormsLimit;	//randomize the current worm that will play now
	// while the turn is not over - keep playing, or while the player didnt picked feature-weapon
	while (!timesUp()) //needs to be change
	{
		checkIfEventOccured(window, event);
		wormMove();
		drawBoardAndAnimation(window, groupPlayers, featuresMenu);
		if (m_drawWeaponMenu) // in here we'll call the draw weapon menu and in addition we'll handle the click of menu
			chooseWeapon(window, featuresMenu, featuresLocation, groupPlayers);
	}
}

/*this function will check if an event has occured from the player and will
summon handleClick function if the player pressed on the right click,
this means the player wants to use a feature from the feature's tool bar. 
right after handling this case, it will check if the player pressed on 
space click - this means he's wants to exert power and shoot or 
throw grenade (one of the options).*/
void Player::checkIfEventOccured(sf::RenderWindow& window, sf::Event& event)
{
	if (window.pollEvent(event))//wait for event from the player
	{
		switch(event.type)
		{
			case sf::Event::MouseButtonPressed:
				case sf::Mouse::Button::Right:
					m_drawWeaponMenu = true; // set to true so we'll draw the weapon menu after the case!
					break;
				case sf::Event::Closed:
					window.close();
					break;
				break;
			case sf::Event::KeyPressed:
				case sf::Keyboard::Space:
					m_force.restart();
					//in here netanel, karin and yair needs to handle box-2d
					break;
				break;
		}
		switch (event.key.code)
		{
			case sf::Keyboard::Space:
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
				break;
		}
	}
}

/*this function will draw the board and all the animations
and objects+all the of the physical elements.*/
void Player::drawBoardAndAnimation(sf::RenderWindow& window, std::vector<std::unique_ptr<Player>>& groupPlayers
	,sf::RectangleShape& featuresMenu) const
{
	window.clear();
	m_world->Step(TIMESTEP, VELITER, POSITER);
	m_board->draw(window);
	if (m_drawWeaponMenu)
		window.draw(featuresMenu);

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

/*this function will draw the worms on the board+animations by using polymorphizm
in draw of Worm class.*/
void Player::draw(sf::RenderWindow& window) const
{
	for (auto& i : m_worms)
		i->draw(window);
}

void Player::chooseWeapon(sf::RenderWindow& window, sf::RectangleShape& featuresMenu,
	std::vector<sf::Vector2f> featuresLocation,
	std::vector<std::unique_ptr<Player>>& groupPlayers)
{
	while (m_drawWeaponMenu && !timesUp()) // while we still want to use the weapon Menu
	{
		drawBoardAndAnimation(window, groupPlayers, featuresMenu);
		if (auto event = sf::Event{}; window.pollEvent(event))
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
					auto location = locatin(window, event); //will return where pressed on board
					checkClick(location, featuresLocation);
					//handleFeatureChoosing(featureToCreate, currWorm, window);
					auto place = m_feature->getPlace();
					auto imageCount = m_feature->getImageCount();
					auto distance = m_feature->getDistance();
					m_worms[m_currWormPlayer]->setAnimation(Resources::instance().getTexture(place),
						imageCount, 0.05f, distance);
				}
				m_drawWeaponMenu = false;
				break;
			}
		}
	}	
}


/*this function will check if the player didn't choose a feature from the tool bar
and if he chosed a feature we'll set the animation of the feature (switch from regular
worm to worm with feature)*/
void Player::handleFeatureChoosing(animationData featureToCreate, int currWorm, sf::RenderWindow& window)
{
	if (featureToCreate.first == -1)
		return;
	m_worms[currWorm]->setAnimation(Resources::instance().getTexture(featureToCreate.first),
		featureToCreate.second, animationSwitchTime, 1);
	handleCollision(featureToCreate.first, window);
}

/*
This function is handling the player click on the weapons tool bar and will check which feature
the player is asking to use. in addition after getting the feature's type we'll create
the Object for the rellevant feature.
*/
void Player::checkClick(sf::Vector2f clickLocation,
	std::vector<sf::Vector2f> featuresLocation)
{
	for (auto i = featuresLocation.begin(); i != featuresLocation.end(); ++i)
	{
		if (abs(clickLocation.x - i->x) < squareSize && abs(clickLocation.y - i->y) < squareSize)
		{
			getFeaturesName(std::distance(featuresLocation.begin(), i) + featureDistance);
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
}

//---------------------------------------------

//this function will convert the location we got on the board to vector 2f
sf::Vector2f Player::locatin(sf::RenderWindow& window, sf::Event& event) const
{
	return window.mapPixelToCoords(
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
		auto i = std::make_unique<Worm>(loc, m_name, m_color, *m_world.get());
		it.swap(i);
	}
}

//-----------------------------------------------------------------

void Player::handleCollision(int wep, sf::RenderWindow& window)
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
		handleSkip(window);
		//wait for press and end the section
		break;
	}
}

void Player::handleWhiteFlag(sf::RenderWindow& window)
{
	for (auto& i : m_worms)
	{
		i->setAnimation(Resources::instance().getTexture(animation_whiteFlag), whiteFlagImageCount, 0.03f, 1);
	}
}

void Player::handleSkip(sf::RenderWindow& window)
{
	while (m_roundTimer.getElapsedTime().asSeconds() > 1.f)
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

void Player::getFeaturesName(int index)
{
	auto wormPosition = m_worms[m_currWormPlayer]->getPosition();
	
	switch (index)
	{
	case animaiton_sheep:
		m_feature = std::make_unique<Sheep>(*m_world.get(), wormPosition);
		break;
	case animation_grenade:
		m_feature = std::make_unique<Grenade>(*m_world.get(), wormPosition);
		break;
	case animation_flick:
		m_feature = std::make_unique<Flick>(*m_world.get(), wormPosition);
		break;
	case animation_axe:
		m_feature = std::make_unique<Axe>(*m_world.get(), wormPosition);
		break;
	case animation_teleporter:
		m_feature = std::make_unique<Transform>();
		break;
	case animation_whiteFlag:
		m_feature = std::make_unique<WhiteFlag>();
		break;
	case animation_stinky:
		m_feature = std::make_unique<Stinky>(*m_world.get(), wormPosition);
		break;
	case animation_skip:
		m_feature = std::make_unique<Pass>();
		break;
		m_feature = nullptr;
	}
}