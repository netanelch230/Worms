#pragma once
#include<SFML/Graphics.hpp>

//==============================const timer======================================
const auto oneRound = 3;
//============================player enums=======================================
const auto wormTextBoxCorLeft = sf::Vector2f{ 17, -25 };
const auto wormTextBoxCorRight = sf::Vector2f{ 17, -25 };

//===========================time for round data================================
const auto timeForRoundPosition = sf::Vector2f{ 50, 650 };
const auto timeForRoundCharacter = 20;
//===========================granede angle====================================
const auto RIGHT = sf::Vector2f{ -1,1 };
const auto LEFT = sf::Vector2f{ 1,1 };

//=====================================animation features==============
const auto animationSwitchTime = 0.03f;
//================================================================================
const int colorAmount = 3;
const int recSize = 50;
const int maxTextFields = 3;
// 3 groups is the maximum

const int minGroupIndex = 0;
const int maxGroupIndex = 3;

const int maxHeadlines = 5;
const int gameFormatOptions = 2;
const int colorsOptions = 4;
const int backgroundOptions = 2;

const int timeOfRound = 45;
//=======================================locations on menu=========================================
const float playersBottonXRatio = 150;
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
const auto sizeOfTelleporterWorm = sf::Vector2f{ 100,100 };
const auto sizeOfWalkWorm = sf::Vector2f{ 100,100 };

//===========================================location of tool bar==================================

const auto toolBarXCoordinate = 984;
//=======================================locations of tool bar on Board============================
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

//=======================const of image count of features==============================
const auto whiteFlagImageCount = sf::Vector2u{ 1,10 };
const auto stinkyImageCount = sf::Vector2u{ 1,10 };
const auto GreenGrenadeImageCount = sf::Vector2u{ 1,32 };
const auto skipImageCount = sf::Vector2u{ 1,9 };
const auto sheepImageCount = sf::Vector2u{ 1,10 };
const auto teleporterImageCount = sf::Vector2u{ 1,10 };
const auto wormImageCount = sf::Vector2u{ 1,36 };
const auto WormDieImageCount = sf::Vector2u{ 1,60 };
const auto artilaryimagecount= sf::Vector2u{ 1,10 };
const auto patrol= sf::Vector2u{ 1,20 };
const auto callartilary= sf::Vector2u{ 1,9 };
const auto walkImageCount = sf::Vector2u{ 1,10 };
const auto dinamitstop= sf::Vector2u{ 1,17};
const auto dinamitbegin= sf::Vector2u{ 1,17};



const auto exGrenadeImageCount = sf::Vector2u{ 1,12 };
const auto exSheepImageCount = sf::Vector2u{ 1,20 };

const auto stinkyAnimationImageCaount= sf::Vector2u{ 1,7 };

const auto arrowImageCount = sf::Vector2u{ 1,30 };

const auto sizeOfStinky = sf::Vector2f{ 54,36 };


const auto posPlayButton = sf::Vector2f{ 850, 300 };
const auto posExitButton = sf::Vector2f{ 50, 300 };
const auto posHelpButton = sf::Vector2f{ 95, 640 };
const auto posPlayCompButton = sf::Vector2f{ 20, 200 };
const auto posPlayFriendButton = sf::Vector2f{ 20, 350 };
const auto map1Button = sf::Vector2f{ 920, 220 };
const auto map2Button = sf::Vector2f{ 920, 380 };
const auto playerButtonPos = sf::Vector2f{ 450, 200 };
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
const int featureDistance = 23;
//==============================features Animation enums!====================================================
enum menuPictures
{
	menuPic1,
	menuPic2,
	backGround1pic,
	backGround2pic,
	start,
	exitGame,
	playTwo,
	playThree,
	helpButton,
	helpPic
};

enum jerusalemMap
{
	featuresMenu = 10,
	jeruland1,
	westrenWall,
	lionGate,
	daviaTower,
	jeruBack
};

enum desertMap
{
	cactus=16,
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
	animation_worm=24,
	animation_artilary,
	animation_whiteFlag,
	animation_begin_dinamit,
	animation_grenade,
	animation_skip,
	animaiton_sheep,
	animation_stinky,
	animation_teleporter,
	animation_die,
	animation_end_dinamit,
	animation_walk
};


enum featuresWeaponesAnim
{
	sheep=36,
	grenade,
	stinky,
	dinamit,
	artileri
};

enum weaponsEffect
{
	exGrenade=41,
	exSheep,
	exStinky
};

enum menuHeadlines
{
	gameMapHeadline=44,
	playersNamesHeadline,
	groupAmountHeadlines
};

enum arrow {
	greenArrow=47,
	blueArrow,
	redArrow
};

enum featuresToolbar {
	artileryIconButton= 50,
	flagIconButton,
	dinamitIconButton,
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

enum sound {
	timer
};

