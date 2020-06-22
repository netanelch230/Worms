#pragma once
#include<SFML/Graphics.hpp>

const int colorAmount = 4;
const int recSize = 50;
const int maxTextFields = 4;
// 4 groups is the maximum

const int minGroupIndex = 0;
const int maxGroupIndex = 3;

const int maxHeadlines = 5;
const int gameFormatOptions = 2;
const int colorsOptions = 4;
const int backgroundOptions = 2;

const int timeOfRound = 45;
//=======================================locations on menu=========================================
const float playersBottonX = 300;
const float playersBottonXRatio = 150;
const float playersBottonY = 200;
const float gameFormatX = 10;

const size_t wormsLimit = 5;
const auto NumOfLife = 150;
const int WIDTH = 1200;
const int HEIGHT = 700;
const int amuntOfPicture = 51;
const int countOfFont = 3;
const int countOfMusic = 5;
const auto sizeOfIcon = sf::Vector2f{ 20,30 };
const auto sizeOfWorm = sf::Vector2f { 40,40 };

//=======================================locations on Board=========================================

const auto featuresCoordinates = sf::Vector2f{ 216, 104 };

//=======================================locations on Board=========================================

const int rowsInTable = 2;
const int colsInTable = 4;
const int squareSize = 50;

//=======================const of image count of features==============================
const auto flickImageCount = sf::Vector2u{ 1,17 };
const auto whiteFlagImageCount = sf::Vector2u{ 1,10 };
const auto axeImageCount = sf::Vector2u{ 1,15 };
const auto stinkyImageCount = sf::Vector2u{ 1,10 };
const auto GreenGrenadeImageCount = sf::Vector2u{ 1,32 };
const auto skipImageCount = sf::Vector2u{ 1,9 };
const auto sheepImageCount = sf::Vector2u{ 1,36 };
const auto teleporterImageCount = sf::Vector2u{ 1,36 };
const auto wormImageCount = sf::Vector2u{ 1,36 };

const auto sizeOfShelf = sf::Vector2f{ 70,50 };
const auto sizeOfStone = sf::Vector2f{ 50,50 };


const auto posPlayButton = sf::Vector2f{ 850, 300 };
const auto posExitButton = sf::Vector2f{ 50, 300 };
const auto posPlayCompButton = sf::Vector2f{ 20, 200 };
const auto posPlayFriendButton = sf::Vector2f{ 20, 350 };
const auto map1Button = sf::Vector2f{ 920, 220 };
const auto map2Button = sf::Vector2f{ 920, 380 };
const auto playerButtonPos = sf::Vector2f{ 300, 200 };
const auto playButtonPos = sf::Vector2f{ 950, 580 };

const int playerDistance = 150;
const int playgameButton = 32;

const auto gameFormatPos = sf::Vector2f{ 5, 120 };
const auto gameMapPos = sf::Vector2f{ 900, 120 };
const auto playersAmountPos = sf::Vector2f{ 320, 150 };
const auto groupNamePos = sf::Vector2f{ 380, 300 };

enum featuresAnim
{
	f_worm=15,
	f_sheep,
	f_grenade,
	f_flick,
	f_axe,
	f_teleporter,
	f_whiteFlag,
	f_stinky,
	f_skip = 23
};

enum features
{
	sheep=24,
	grenade,
	flick,
	axe,
	teleporter,
	whiteFlag,
	stinky,
	skip
};

enum menuHeadlines
{
	gameFormatHeadline = 33,
	gameMapHeadline,
	playersNamesHeadline,
	groupAmountHeadlines
};

enum sides
{
	jump,
	down,
	left,
	right,
	stand
};

enum e_music
{
	gamemusic,
	deathmusic,
	diamondmusic
};



enum font
{
	menu_font,
	name_font
};
enum color
{
	yellow,
	blue,
	red,
	green
};

enum menuFields
{
	gameFormat,
	gameBackground,
	numberOfPlayers,
	groupColor,
	groupName
};

enum menuPress
{
	t_update,
	t_end,
	t_startPlay
};

enum menuPictures
{
	menuPic1,
	menuPic2,
	playWithFriendsPic,
	playWithComputerPic,
	backGround1pic,
	backGround2pic,
	start,
	exitGame,
	p1,
	p2,
	p3,
	p4
};

enum board
{
	featuresMenu=12,
	shelf,
	stone
};

