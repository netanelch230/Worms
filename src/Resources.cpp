#include "Resources.h"
#include "Enum.h"

Resources& Resources::instance()
{
	static Resources instance;
	return instance;
}


void Resources::loadPicture()
{
	m_picture[menuPic1].loadFromFile("menuBackground1.png");
	m_picture[menuPic2].loadFromFile("menuBackground2.png");
	m_picture[backGround1pic].loadFromFile("jerusalemButton.PNG");
	m_picture[backGround2pic].loadFromFile("desertButton.png");
	m_picture[start].loadFromFile("start.png");
	m_picture[exitGame].loadFromFile("exit.png");
	m_picture[playTwo].loadFromFile("p2.png");
	m_picture[playThree].loadFromFile("p3.png");
	m_picture[helpButton].loadFromFile("helpButton.png");
	m_picture[helpPic].loadFromFile("help.png");

	m_picture[featuresMenu].loadFromFile("featuresMenu.png");

	//load background and board to Jerusalem map
	m_picture[jeruland1].loadFromFile("jeruLand1.png");
	m_picture[daviaTower].loadFromFile("davidTower.png");
	m_picture[jeruBack].loadFromFile("jeruBack.png");
	m_picture[lionGate].loadFromFile("lionGate.png");
	m_picture[westrenWall].loadFromFile("wastrenWall.png");

	//load background and board to Jerusalem map
	m_picture[cactus].loadFromFile("cactus.png");
	m_picture[camel].loadFromFile("camel.png");
	m_picture[desertBack].loadFromFile("desertBack.png");
	m_picture[desertLand3].loadFromFile("desertLand3.png");
	m_picture[desertLand4].loadFromFile("desertLand4.png");
	m_picture[desertLand7].loadFromFile("desertLand7.png");
	m_picture[tent].loadFromFile("tent.png");
	m_picture[waterWall].loadFromFile("waterWall.png");

	//load animations!
	m_picture[animation_worm].loadFromFile("worm.png");
	m_picture[animaiton_sheep].loadFromFile("sheep.png");
	m_picture[animation_whiteFlag].loadFromFile("whiteFlag.png");
	m_picture[animation_grenade].loadFromFile("greenGrenade.png");
	m_picture[animation_begin_dinamit].loadFromFile("wormDinamitBegin.png");
	m_picture[animation_end_dinamit].loadFromFile("wormDinamitSof.png");
	m_picture[animation_artilary].loadFromFile("callRocketAnimation.png");
	m_picture[animation_teleporter].loadFromFile("telleporter.png");
	m_picture[animation_walk].loadFromFile("wwalkd.png");
	m_picture[animation_skip].loadFromFile("pass.png");
	m_picture[animation_die].loadFromFile("wdie.png");
	m_picture[animation_stinky].loadFromFile("stinkyAnimation.png");


	m_picture[grenade].loadFromFile("GRENADE1.png");
	m_picture[sheep].loadFromFile("sheepWalk.png");
	m_picture[dinamit].loadFromFile("dynamite.png");
	m_picture[artileri].loadFromFile("artilary.png");
	m_picture[stinky].loadFromFile("stinkyWalk.png");

	m_picture[exGrenade].loadFromFile("exGrenade.png");
	m_picture[exSheep].loadFromFile("exSheep.png");
	m_picture[exStinky].loadFromFile("exStinky.png");
	

	//load menu headlines and start game button
	m_picture[playgameButton].loadFromFile("play.png");
	m_picture[gameMapHeadline].loadFromFile("gameMap.png");
	m_picture[playersNamesHeadline].loadFromFile("groupName.png");
	m_picture[groupAmountHeadlines].loadFromFile("playersNum.png");

	//load thhw arrow
	m_picture[greenArrow].loadFromFile("arrowGreen.png");
	m_picture[blueArrow].loadFromFile("arrowBlue.png");

	m_picture[artileryIconButton].loadFromFile("airstrkeButton.png");
	m_picture[dinamitIconButton].loadFromFile("dynamiteButton.png");
	m_picture[flagIconButton].loadFromFile("flagIconButton.png");
	m_picture[grenadeIconButton].loadFromFile("grenadeIconButton.png");
	m_picture[passIconButton].loadFromFile("passIconButton.png");
	m_picture[sheepIconButton].loadFromFile("sheepIconButton.png");
	m_picture[stinkyIconButton].loadFromFile("stinkyIconButton.png");
	m_picture[teleportIconButton].loadFromFile("teleportIconButton.png");

}

void Resources::loadFont()
{
	m_font[menu_font].loadFromFile("herist.otf");
	m_font[name_font].loadFromFile("tahoma.ttf");
	
}

void Resources::loadSound()
{
	m_sound[timer].loadFromFile("WARNINGBEEP.wav");
	m_sound[explosion1].loadFromFile("Explosion1.wav");
	m_sound[explosion2].loadFromFile("PETROL.wav");
	m_sound[clap].loadFromFile("CrowdPart2.wav");
	m_sound[Coughe].loadFromFile("Cough2.wav");
	m_sound[artilary].loadFromFile("Airstrike.wav");
	m_sound[pain].loadFromFile("ow1.wav");
	m_sound[mourse].loadFromFile("Morse.wav");
	m_sound[buttonClick].loadFromFile("KEYCLICK.wav");
	m_sound[skunk_walk].loadFromFile("SkunkWalkLoop.wav");
	m_sound[skunk_gas].loadFromFile("SkunkGasLoop.wav");
	m_sound[sheep_baa].loadFromFile("SHEEPBAA.wav");
	//m_sound[byebye].loadFromFile("BYEBYE.wav");
	m_sound[worm_walk1].loadFromFile("Walk-Compress.wav");
	m_sound[worm_walk2].loadFromFile("Walk-Expand.wav");
	m_sound[transform].loadFromFile("TELEPORT.wav");

}
sf::Vector2f operator+(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1 += v2;
}

sf::Vector2f randomLocation(int height, int width)
{
	//srand(time(NULL));
	float randPlaceX = (rand() % height) +10;
	float randPlaceY = (rand() % width) + 10;

	return sf::Vector2f{ randPlaceX, randPlaceY };
}