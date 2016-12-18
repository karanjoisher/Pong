#pragma once
#include "stdafx.h"
struct Resources
{
	//FONTS
	static sf::Font arcadeFont;
	static sf::Font kenVectorFont;

	//COLORS
	static sf::Color green;
	static sf::Color blue;
	static sf::Color purple;
	
	//PATHS TO RESOURCES
	static std::string arcadeFontPath;
	static std::string kenVectorFontPath;
	static std::string paddleTexturePath;
	static std::string homeScreenSoundPath;
	static std::string mouseClickSoundPath;
	static std::string greenUITexturePath;
	static std::string blueUITexturePath;
	static std::string fieldTexturePath;
	static std::string mouseOverSoundPath;
	static std::string backgroundTexturePath;
	static std::string wallHitSoundPath;
	static std::string paddleHitSoundPath;
	static std::string playerMissSoundPath;
	static std::string ballTexturePath;

	//SOUND BUFFERS
	static sf::SoundBuffer mouseOverBuffer;
	static sf::SoundBuffer homeScreenSoundBuffer;
	static sf::SoundBuffer mouseClickBuffer;
	static sf::SoundBuffer wallHitBuffer;
	static sf::SoundBuffer paddleHitBuffer;
	static sf::SoundBuffer playerMissBuffer;

	//SOUNDS
	static sf::Sound homeScreen;
	static sf::Sound mouseOver;
	static sf::Sound wallHit;
	static sf::Sound paddleHit;
	static sf::Sound playerMiss;
	static sf::Sound mouseClick;

	//TEXTURES
	static sf::Texture fieldTexture;
	static	sf::Texture backgroundTexture;
	static sf::Texture paddleTexture;
	static sf::Texture ballTexture;
	static sf::Texture greenUITexture;
	static sf::Texture blueUITexture;

	//SPRITES
	static sf::Sprite paddleSprite;
	static	sf::Sprite fieldSprite;
	static sf::Sprite backgroundSprite;
	static sf::Sprite ballSprite;
	static sf::Sprite whiteGreenButton;
	static sf::Sprite greenButton;
	static sf::Sprite greenUp;
	static sf::Sprite greenRight;
	static sf::Sprite greenLeft;
	static sf::Sprite greenDown;
	static sf::Sprite whiteGreenBox;
	static sf::Sprite whiteBlueBox;
	static sf::Sprite blueRight;
	static sf::Sprite blueLeft;
	static sf::Sprite blueButton;
	static sf::Sprite whiteBlueButton;
	static sf::Sprite blueUp;
	static sf::Sprite blueDown;

	//LOAD ALL OF THE ABOVE
	static void load();
};