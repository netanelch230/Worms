#include "Resource.h"
#include "Enum.h"

Resource& Resource::instance()
{
	static Resource instance;
	return instance;
}


void Resource::loadPicture()
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

	//load background and board to Jerusalem map
	m_picture[jeruLand].loadFromFile("jeruLand.png");
	m_picture[jeruBack].loadFromFile("jeruBack.png");
	m_picture[jaffaGate].loadFromFile("jaffaGate.png");
	m_picture[kneset].loadFromFile("kneset.png");

	//load background and board to Jerusalem map
	
	m_picture[camel].loadFromFile("camel.png");
	m_picture[desertBack].loadFromFile("desertBack.png");
	m_picture[desertLand].loadFromFile("desertLand.png");
	m_picture[desertHome].loadFromFile("desertHome.png");
	m_picture[waterWall].loadFromFile("waterWall.png");

	//load animations!
	m_picture[animation_worm].loadFromFile("worm.png");
	m_picture[animaiton_sheep].loadFromFile("sheep.png");
	m_picture[animation_whiteFlag].loadFromFile("whiteFlag.png");
	m_picture[animation_grenade].loadFromFile("greenGrenade.png");
	m_picture[animation_begin_dinamit].loadFromFile("wormDinamitBegin.png");
	m_picture[animation_win].loadFromFile("wwinner.png");/////// change
	m_picture[animation_teleporter].loadFromFile("telleporter.png");
	m_picture[animation_walk].loadFromFile("wwalkd.png");
	m_picture[animation_skip].loadFromFile("pass.png");
	m_picture[animation_die].loadFromFile("wdie.png");
	m_picture[animation_stinky].loadFromFile("stinkyAnimation.png");
	m_picture[animation_grave1].loadFromFile("grave1.png");
	m_picture[animation_grave2].loadFromFile("grave2.png");
	m_picture[animation_grave3].loadFromFile("grave3.png");
	//m_picture[animation_win].loadFromFile("wwinner.png");



	m_picture[grenade].loadFromFile("GRENADE1.png");
	m_picture[sheep].loadFromFile("sheepWalk.png");
	m_picture[dinamit].loadFromFile("dynamite.png");
	m_picture[artileri].loadFromFile("artilary.png");
	m_picture[stinky].loadFromFile("stinkyWalk.png");

	m_picture[exGrenade].loadFromFile("exGrenade.png");
	m_picture[exSheep].loadFromFile("exSheep.png");
	m_picture[exStinky].loadFromFile("exStinky.png");
	m_picture[exArtilary].loadFromFile("exArtilary.png");
	m_picture[exDynamite].loadFromFile("exDynamite.png");
	

	//load menu headlines and start game button
	m_picture[playgameButton].loadFromFile("play.png");
	m_picture[gameMapHeadline].loadFromFile("gameMap.png");
	m_picture[playersNamesHeadline].loadFromFile("groupName.png");
	m_picture[groupAmountHeadlines].loadFromFile("playersNum.png");

	//load thhw arrow
	m_picture[greenArrow].loadFromFile("arrowGreen.png");
	m_picture[blueArrow].loadFromFile("arrowBlue.png");

	m_picture[speedButtonIcon].loadFromFile("speedButtonIcon.png");
	m_picture[dinamitIconButton].loadFromFile("dynamiteButton.png");
	m_picture[flagIconButton].loadFromFile("flagIconButton.png");
	m_picture[grenadeIconButton].loadFromFile("grenadeIconButton.png");
	m_picture[passIconButton].loadFromFile("passIconButton.png");
	m_picture[sheepIconButton].loadFromFile("sheepIconButton.png");
	m_picture[stinkyIconButton].loadFromFile("stinkyIconButton.png");
	m_picture[teleportIconButton].loadFromFile("teleportIconButton.png");

	m_picture[endGame].loadFromFile("endGame.png");
}

void Resource::loadFont()
{
	m_font[menu_font].loadFromFile("herist.otf");
	m_font[name_font].loadFromFile("tahoma.ttf");
	
}

void Resource::loadSound()
{
	m_sound[timer].loadFromFile("WARNINGBEEP.wav");
	m_sound[explosion1].loadFromFile("Explosion1.wav");
	m_sound[clap].loadFromFile("CrowdPart2.wav");
	m_sound[Coughe].loadFromFile("Cough2.wav");
	m_sound[artilary].loadFromFile("Airstrike.wav");
	m_sound[pain].loadFromFile("ow1.wav");
	m_sound[mourse].loadFromFile("Morse.wav");
	m_sound[buttonClick].loadFromFile("KEYCLICK.WAV");
	m_sound[skunk_walk].loadFromFile("SkunkWalkLoop.wav");
	m_sound[skunk_gas].loadFromFile("SkunkGasLoop.wav");
	m_sound[sheep_baa].loadFromFile("SHEEPBAA.wav");
	m_sound[wormByeBye].loadFromFile("BYEBYE.wav");
	m_sound[explosion2].loadFromFile("PETROL.wav");
	m_sound[worm_walk1].loadFromFile("Walk-Compress.wav");
	m_sound[worm_walk2].loadFromFile("Walk-Expand.wav");
	m_sound[transform].loadFromFile("TELEPORT.wav");
	m_sound[wormjump].loadFromFile("JUMP1.wav");
	m_sound[run_away].loadFromFile("RUNAWAY.WAV");
	m_sound[start_round].loadFromFile("StartRound.wav");

}
void Resource::loadMusic()
{
	m_music[openSong].loadFromFile("OpenSong.ogg");
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

sf::Texture& image(int i)
{
	return Resource::instance().getTexture(i);
}

sf::Font& font(int i)
{
	return Resource::instance().getfont(i);
}

sf::SoundBuffer& Music(int i)
{
	return Resource::instance().getMusic(i);
}

sf::SoundBuffer& song(int i)
{
	return Resource::instance().getSong(i);
}
