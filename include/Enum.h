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
const int countOfPicture = 16;
const int countOfFont = 3;
const int countOfMusic = 5;
const auto sizeOfIcon = sf::Vector2f{ 20,30 };
const auto sizeOfWorm = sf::Vector2f { 70,70 };

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
//sf::Vector2u sheepImageCount = { 1,36 };


enum featuresMenu
{
	f_sheep,
	f_grenade,
	f_flick,
	f_axe,
	f_move,
	f_whiteFlag,
	f_stinky,
	f_skip
};


enum menuOption
{
	arrbackground
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

enum Icon
{
	flik=1,
	grenade,
	pass,
	sheep,
	whiteflag
};

enum Anomation
{
	worm,
	axe
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

enum Pictures
{
	menuPic,
	menuHeadline,
	playWithFriendsPic,
	playWithComputerPic,
	backGround1pic,
	backGround2pic,
	startPlay,
	featuresMenu
};

