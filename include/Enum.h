#pragma once
#include<SFML/Graphics.hpp>

//=============================menu + Buttons Enums======================================

const int endGame = 60;//for end Game screen.
const int playgameButton = 90;
const int backgroundOptions = 2;
const float playersBottonXRatio = 150;
const float gameFormatX = 10;
const auto posPlayButton = sf::Vector2f{ 850, 300 };
const auto posExitButton = sf::Vector2f{ 50, 300 };
const auto posHelpButton = sf::Vector2f{ 50, 620 };
const auto posPlayCompButton = sf::Vector2f{ 20, 200 };
const auto posPlayFriendButton = sf::Vector2f{ 20, 350 };
const auto map1Button = sf::Vector2f{ 920, 220 };
const auto map2Button = sf::Vector2f{ 920, 380 };
const auto playerButtonPos = sf::Vector2f{ 450, 200 };
const auto playButtonPos = sf::Vector2f{ 950, 580 };
const auto gameFormatPos = sf::Vector2f{ 5, 120 };
const auto gameMapPos = sf::Vector2f{ 900, 120 };
const auto playersAmountPos = sf::Vector2f{ 320, 150 };
const auto groupNamePos = sf::Vector2f{ 380, 300 };
const int groupAmountDis = 2;
const int PlayerButtonAmount = 2;
const auto recSize = sf::Vector2f{ 150, 40 };
const int recXPos = 500;
const int recYPos = 380;
const int SpritePlayerAmount = 2;
const int headLineAmount = 3;
const std::string defaultName = "User";
const int concatenation = 1;
//===========================player text menu enums============================
const int charSize = 25;
const auto textBold = sf::Text::Bold;
const float xOrigin = 0;
const float yOrigin = 10;
const float textFloatX = 505;
const float textFloatY = 393;
const int posDis = 70;

//===========================color menu enums============================
const auto recColor = sf::Vector2f{ 40 ,40 };
const int colorXPos = 700;

//============================player enums - directions========================

const auto wormTextBoxCorLeft = sf::Vector2f{ -25, -60 };
const auto wormTextBoxCorRight = sf::Vector2f{ -25, -60};

//===========================time for round data================================

const auto oneRound = 5;
const auto timeForRoundPosition = sf::Vector2f{ 30, 660 };
const auto timeForRoundCharacter = 20;
const auto speedRunTimer= 10;
const int timeOfRound = 45;
const auto timesUP = -1;


//===========================grenade angle====================================

const auto RIGHT = sf::Vector2f{ -1,1 };
const auto LEFT = sf::Vector2f{ 1,1 };
const auto featureRight = sf::Vector2f{ 1,1 };
const auto featureLeft = sf::Vector2f{ -1,1 };

//=====================================animation Feature=======================

const auto animationSwitchTime = 0.05f;

//==================================worms enums================================

const auto wormsLimit = 5;
const auto initCount = 0; // the beginning of the vector
const auto maxCount = wormsLimit - 1; // this is max count of worms in the vector
const bool win = true;
const int startIndex = 0;
const int empty = 0;
const int lastGroup = 1;
const auto NumOfLife = 150;


//=========================group color enums in menu===========================
const int colorsOptions = 3;
const int maxTextFields = 3;

//=================================audio, font and pictures enums=================================
const int songCount = 1;
const int countOfMusic = 40;
const int amuntOfPicture = 100;
const int countOfFont = 3;
const int volume = 20;

//=======================================locations on menu=========================================

//=================================window enums================================

const int WIDTH = 1280;
const int HEIGHT = 720;
const auto randomWidth = WIDTH - 10;
const auto randomHight = HEIGHT - 10;

//==========================size of animations (in pixels)==========================

const auto sizeOfIcon = sf::Vector2f{ 20,30 };
const auto sizeOfWorm = sf::Vector2f { 20,20 };
const auto sizeOfPassWorm = sf::Vector2f{ 100,100 };
const auto sizeOfWhiteFlagWorm = sf::Vector2f{ 90,90 };
const auto sizeOfTelleporterWorm = sf::Vector2f{ 100,100 };
const auto sizeOfWalkWorm = sf::Vector2f{ 44,42 };
const auto sizeOfAnimationArtilary = sf::Vector2f{ 60,60 };
const auto wormPositionAddition = sf::Vector2f{ 0,5 };
const auto sizeOfWinAnimation = sf::Vector2f{  140,140  };
const auto sizeOfWhiteFlag = sf::Vector2f{ 20,20 };



//==================================ToolBar Enums==============================

const auto toolBarXCoordinate = 984;
const int rowsInTable = 2;
const int colsInTable = 4;

//========================================Feature==============================

const auto FeatureAmount = 8;
const auto FeatureEnum = 53;
const float feautersX = 1000.0;
const float feautersY = 80.0;
const int feauterSize = 32;
const auto FeatureCoordinates = sf::Vector2f{ 216, 104 };

//=======================const of image count of Feature==============================
const auto whiteFlagImageCount = sf::Vector2u{ 1,16 };
const auto WormWhiteFlagImageCount = sf::Vector2u{ 1,16 };
const auto stinkyImageCount = sf::Vector2u{ 1,10 };
const auto GreenGrenadeImageCount = sf::Vector2u{ 1,1 };
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
const auto dinamitExImageCount = sf::Vector2u{1, 31};
const auto exGrenadeImageCount = sf::Vector2u{ 1,12 };
const auto exSheepImageCount = sf::Vector2u{ 1,20 };
const auto exSkunkImageCount = sf::Vector2u{ 1, 24};
const auto winImageCount = sf::Vector2u{ 1, 14};
const auto stinkyAnimationImageCaount= sf::Vector2u{ 1,7 };
const auto arrowImageCount = sf::Vector2u{ 1,30 };
const auto sizeOfStinky = sf::Vector2f{ 54,36 };
const int playerDistance = 150;

const auto graveImageCount = sf::Vector2u{ 1,20 };
const float PPM = 64.f;                     /////convert to world cords
const float MPP = 0.015625f;                //////convert to world cords


//=======================================animation Enums=======================
const int amountOfAnimation = 9;
const int featureDistance = 21; // the distance of animation from the beginning


//=============================================================================

enum headLinePositions
{
	map = 0,
	name,
	amount
};
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
	FeatureMenu = 10,
	jeruLand,
	jeruBack,
	jaffaGate,
	kneset,
};

enum desertMap
{
	camel=15,
	desertBack,
	desertLand,
	desertHome,
	waterWall
};

enum FeatureWormAnim
{
	animation_worm=20,
	animation_walk,
	animation_whiteFlag,
	animation_begin_dinamit,
	animation_grenade,
	animation_skip,
	animaiton_sheep,
	animation_stinky,
	animation_teleporter,
	animation_die,
	animation_win,
	animation_grave1,
	animation_grave2,
	animation_grave3

};


enum FeatureWeaponesAnim
{
	sheep=34,
	grenade,
	stinky,
	dinamit,
	artileri
};

enum weaponsEffect
{
	exGrenade=39,
	exSheep,
	exStinky,
	exArtilary,
	exDynamite
};

enum menuHeadlines
{
	gameMapHeadline=44,
	playersNamesHeadline,
	groupAmountHeadlines
};

enum arrow 
{
	greenArrow=47,
	blueArrow,
	redArrow
};

enum FeatureToolbar 
{
	speedButtonIcon= 50,
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

enum sound 
{
	timer,
	explosion1,
	clap,
	Coughe,
	artilary,
	pain,
	mourse,
	buttonClick,
	skunk_walk,
	skunk_gas,
	sheep_baa,
	explosion2,
	worm_walk1,
	worm_walk2,
	transform,
	wormByeBye,
	wormjump,
	run_away,
	start_round

};

enum featureCondition 
{
	startAnimation,
	alive,
	bomb,
	bombAnimation,
	endBombAnimation,
	endFeatur
};

enum music
{
	openSong
};

