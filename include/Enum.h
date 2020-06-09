#pragma once

const int colorAmount = 4;
const size_t wormsLimit = 5;
const auto NumOfLife = 150;
const int WIDTH = 1200;
const int HEIGHT = 700;
const int recSize = 50;
const int maxTextFields = 4;
// 4 groups is the maximum
const int minGroupIndex = 0;
const int maxGroupIndex = 3;

const int maxHeadlines = 5;
const int gameFormatOptions = 2;
const int colorsOptions = 4;
const int backgroundOptions = 2;

enum font
{
	menu_font
};
enum color
{
	yellow,
	blue,
	red,
	green
};

enum Pictures
{
	menuPic,
	menuHeadline,
	maxTextures
};

enum menuFields
{
	gameFormat,
	gameBackground,
	numberOfPlayers,
	groupColor,
	groupName
};