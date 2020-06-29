#pragma once
#include<SFML/Graphics.hpp>

//==============================const timer======================================

//============================player enums=======================================
const auto wormTextBoxCorLeft = sf::Vector2f{ 17, -25 };
const auto wormTextBoxCorRight = sf::Vector2f{ -17, -25 };

//===========================time for round data================================
const auto timeForRoundPosition = sf::Vector2f{ 50, 650 };
const auto timeForRoundCharacter = 20;
//===========================granede angle====================================
const auto RIGHT = sf::Vector2f{ -1,1 };
const auto LEFT = sf::Vector2f{ 1,1 };

//=====================================animation features==============
const auto animationSwitchTime = 0.03f;
//================================================================================
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
const int WIDTH = 1280;
const int HEIGHT = 720;
const int amuntOfPicture = 100;
const int countOfFont = 3;
const int countOfMusic = 5;
const auto sizeOfIcon = sf::Vector2f{ 20,30 };
const auto sizeOfWorm = sf::Vector2f { 20,20 };
const auto sizeOfPassWorm = sf::Vector2f{ 100,100 };
const auto sizeOfWhiteFlagWorm = sf::Vector2f{ 100,100 };

//===========================================location of tool bar==================================

const auto toolBarXCoordinate = 984;
//=======================================locations of tool bar on Board=============================

const auto axeIcon = sf::Vector2f{ 216, 104 };
const auto flagIcon = sf::Vector2f{ 248, 104 };
const auto flickIcon = sf::Vector2f{ 280, 104 };
const auto grenadeIcon = sf::Vector2f{ 312, 104 };
const auto passIcon = sf::Vector2f{ 216, 136 };
const auto sheepIcon = sf::Vector2f{ 216, 168 };
const auto stinkyIcon = sf::Vector2f{ 216, 200 };
const auto teleportIcon = sf::Vector2f{ 216, 232 };

const float feautersX = 1000.0;
const float feautersY = 80.0;
const int feauterSize = 32;
const auto featuresCoordinates = sf::Vector2f{ 216, 104 };

//========================================number of features button=================================

const auto featuresAmount = 8;
const auto featuresEnum = 53;
//=======================================locations on Board=========================================

const int rowsInTable = 2;
const int colsInTable = 4;
const int squareSize = 50;

//=======================const of image count of features==============================
const auto flickImageCount = sf::Vector2u{ 1,17 };
const auto whiteFlagImageCount = sf::Vector2u{ 1,16 };
const auto axeImageCount = sf::Vector2u{ 1,15 };
const auto stinkyImageCount = sf::Vector2u{ 1,10 };
const auto GreenGrenadeImageCount = sf::Vector2u{ 1,32 };
const auto skipImageCount = sf::Vector2u{ 1,9 };
const auto sheepImageCount = sf::Vector2u{ 1,8 };
const auto teleporterImageCount = sf::Vector2u{ 1,36 };
const auto wormImageCount = sf::Vector2u{ 1,36 };
const auto WormDieImageCount = sf::Vector2u{ 1,60 };
const auto wormAnimationAxe= sf::Vector2u{ 1,15 };



const auto artilaryimagecount= sf::Vector2u{ 1,30 };
const auto patrol= sf::Vector2u{ 1,20 };
const auto callartilary= sf::Vector2u{ 1,10	 };

const auto dinamitstop= sf::Vector2u{ 1,10	 };
const auto dinamitbegin= sf::Vector2u{ 1,10	 };



const auto exGrenadeImageCount = sf::Vector2u{ 1,12 };
const auto exSheepImageCount = sf::Vector2u{ 1,20 };

const auto stinkyAnimationImageCaount= sf::Vector2u{ 1,7 };

const auto arrowImageCount = sf::Vector2u{ 1,30 };

const auto sizeOfStinky = sf::Vector2f{ 54,36 };


const auto posPlayButton = sf::Vector2f{ 850, 300 };
const auto posExitButton = sf::Vector2f{ 50, 300 };
const auto posPlayCompButton = sf::Vector2f{ 20, 200 };
const auto posPlayFriendButton = sf::Vector2f{ 20, 350 };
const auto map1Button = sf::Vector2f{ 920, 220 };
const auto map2Button = sf::Vector2f{ 920, 380 };
const auto playerButtonPos = sf::Vector2f{ 300, 200 };
const auto playButtonPos = sf::Vector2f{ 950, 580 };

const int playerDistance = 150;
const int playgameButton = 90;

const auto gameFormatPos = sf::Vector2f{ 5, 120 };
const auto gameMapPos = sf::Vector2f{ 900, 120 };
const auto playersAmountPos = sf::Vector2f{ 320, 150 };
const auto groupNamePos = sf::Vector2f{ 380, 300 };

//========================================amount of animation===============================================
const int amountOfAnimation = 9;

//==============================distance of animation from the beginning================================
const int featureDistance = 29;
//==============================features Animation enums!====================================================
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

enum jerusalemMap
{
	featuresMenu = 12,
	jeruland1,
	westrenWall,
	lionGate,
	daviaTower,
	jeruBack
};

enum desertMap
{
	cactus=18,
	camel,
	desertBack,
	desertLand3,
	desertLand4,
	desertLand7,
	tent,
	waterWall
};



enum featuresWormAnim
{
	animation_worm=28,
	animaiton_sheep,
	animation_grenade,
	animation_artilary,
	animation_begin_dinamit,
	animation_end_dinamit,
	animation_whiteFlag,
	animation_skip,
	animation_stinky,
	animation_teleporter,
	animation_die
};


enum featuresWeaponesAnim
{
	sheep=39,
	grenade,
	stinky,
	flik,
	dinamit,
	artileri
};

enum weaponsEffect
{
	exGrenade=45,
	exSheep,
	exStinky
};

enum menuHeadlines
{
	gameFormatHeadline = 48,
	gameMapHeadline,
	playersNamesHeadline,
	groupAmountHeadlines
};

enum arrow {
	greenArrow=53,
	blueArrow,
	redArrow
};

enum featuresToolbar {
	axeIconButton= 56,
	flagIconButton,
	flickIconButton,
	grenadeIconButton,
	passIconButton,
	sheepIconButton,
	stinkyIconButton,
	teleportIconButton
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
	red,
	yellow,
	blue,
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



