#pragma once

const int colorAmount = 4;
const size_t wormsLimit = 5;
const auto NumOfLife = 150;
const int WIDTH = 1200;
const int HEIGHT = 700;
const int countOfPicture = 16;
const int countOfFont = 3;
const int countOfMusic = 5;
const auto sizeOfIcon = sf::Vector2f{ 20,30 };
const auto sizeOfWorm = sf::Vector2f { 20,20 };

enum color
{
	yellow,
	blue,
	red,
	green
};

enum menuOption
{
	menuPic,
	gameFormat
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