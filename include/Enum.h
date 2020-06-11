#pragma once
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
const auto sizeOfWorm = sf::Vector2f { 100,100 };

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
};

enum font
{
	menu_font,
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
	statPlay
};
