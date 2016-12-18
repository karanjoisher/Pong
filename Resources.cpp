#include"stdafx.h"
#include"Resources.h"


sf::Font Resources::arcadeFont;
sf::Font Resources::kenVectorFont;

sf::Color Resources::purple (63, 81, 181);
sf::Color Resources::blue (30, 167, 225);
sf::Color Resources::green(115, 205, 75);

sf::Sound Resources::mouseOver;
sf::Sound Resources::homeScreen;
sf::Sound Resources::mouseClick;
sf::Sound Resources::wallHit;
sf::Sound Resources::paddleHit;
sf::Sound Resources::playerMiss;

sf::SoundBuffer Resources::mouseOverBuffer;
sf::SoundBuffer Resources::homeScreenSoundBuffer;
sf::SoundBuffer Resources::mouseClickBuffer;
sf::SoundBuffer Resources::wallHitBuffer;
sf::SoundBuffer Resources::paddleHitBuffer;
sf::SoundBuffer Resources::playerMissBuffer;

std::string Resources::blueUITexturePath = "D:/workspace/Pong/Pong/res/textures/blueSheet.png";
std::string Resources::arcadeFontPath = "D:/workspace/Pong/Pong/res/fonts/ARCADECLASSIC.ttf";
std::string Resources::kenVectorFontPath = "D:/workspace/Pong/Pong/res/fonts/font.ttf";
std::string Resources::paddleTexturePath = "D:/workspace/Pong/Pong/res/textures/paddle.png";
std::string Resources::fieldTexturePath = "D:/workspace/Pong/Pong/res/textures/field.png";
std::string Resources::mouseOverSoundPath = "D:/workspace/Pong/Pong/res/sounds/mouseOver.ogg";
std::string Resources::homeScreenSoundPath = "D:/workspace/Pong/Pong/res/sounds/homeScreenMusic.wav";
std::string Resources::mouseClickSoundPath = "D:/workspace/Pong/Pong/res/sounds/switch3.ogg";
std::string Resources::backgroundTexturePath = "D:/workspace/Pong/Pong/res/textures/background.png";
std::string Resources::greenUITexturePath = "D:/workspace/Pong/Pong/res/textures/greenSheet.png";
std::string Resources::ballTexturePath = "D:/workspace/Pong/Pong/res/textures/ball.png";
std::string Resources::wallHitSoundPath = "D:/workspace/Pong/Pong/res/sounds/wallHit.wav";
std::string Resources::paddleHitSoundPath = "D:/workspace/Pong/Pong/res/sounds/paddleHit.wav";
std::string Resources::playerMissSoundPath = "D:/workspace/Pong/Pong/res/sounds/playerMiss.wav";


sf::Sprite Resources::paddleSprite;
sf::Sprite Resources::backgroundSprite;
sf::Sprite Resources::greenRight;
sf::Sprite Resources::greenLeft;
sf::Sprite Resources::greenButton;
sf::Sprite Resources::whiteGreenButton;
sf::Sprite Resources::greenUp;
sf::Sprite Resources::greenDown;
sf::Sprite Resources::whiteGreenBox;
sf::Sprite Resources::ballSprite;
sf::Sprite Resources::fieldSprite;
sf::Sprite Resources::whiteBlueBox;
sf::Sprite Resources::blueRight;
sf::Sprite Resources::blueLeft;
sf::Sprite Resources::blueButton;
sf::Sprite Resources::whiteBlueButton;
sf::Sprite Resources::blueUp;
sf::Sprite Resources::blueDown;


sf::Texture Resources::blueUITexture;
sf::Texture Resources::greenUITexture;
sf::Texture Resources::paddleTexture;
sf::Texture Resources::backgroundTexture;
sf::Texture Resources::ballTexture;
sf::Texture Resources::fieldTexture;




void Resources::load()
{
	if(Resources::ballTexture.loadFromFile(Resources::ballTexturePath)
	&& Resources::wallHitBuffer.loadFromFile(Resources::wallHitSoundPath)	
	&& Resources::playerMissBuffer.loadFromFile(Resources::playerMissSoundPath)	
	&& Resources::paddleHitBuffer.loadFromFile(Resources::paddleHitSoundPath)	
	&& Resources::fieldTexture.loadFromFile(Resources::fieldTexturePath)	
	&& Resources::mouseOverBuffer.loadFromFile(Resources::mouseOverSoundPath)	
	&& Resources::blueUITexture.loadFromFile(Resources::blueUITexturePath)	
	&& Resources::homeScreenSoundBuffer.loadFromFile(Resources::homeScreenSoundPath)	
	&& Resources::mouseClickBuffer.loadFromFile(Resources::mouseClickSoundPath)	
	&& Resources::backgroundTexture.loadFromFile(Resources::backgroundTexturePath)	
	&& Resources::kenVectorFont.loadFromFile(Resources::kenVectorFontPath)	
	&& Resources::paddleTexture.loadFromFile(Resources::paddleTexturePath)	
	&& Resources::arcadeFont.loadFromFile(Resources::arcadeFontPath)	
	&& Resources::greenUITexture.loadFromFile(Resources::greenUITexturePath))
	{
		Resources::backgroundSprite.setTexture(Resources::backgroundTexture);
		Resources::homeScreen.setBuffer(Resources::homeScreenSoundBuffer);
		Resources::mouseClick.setBuffer(Resources::mouseClickBuffer);
		Resources::mouseOver.setBuffer(Resources::mouseOverBuffer);

		Resources::paddleSprite.setTexture(Resources::paddleTexture);

		Resources::whiteGreenBox.setTexture(Resources::greenUITexture);
		Resources::whiteGreenBox.setTextureRect(sf::IntRect(337, 184, 49, 49));

		Resources::greenUp.setTexture(Resources::greenUITexture);
		Resources::greenUp.setTextureRect(sf::IntRect(416, 72, 28, 42));

		Resources::greenDown.setTexture(Resources::greenUITexture);
		Resources::greenDown.setTextureRect(sf::IntRect(388, 72, 28, 42));

		Resources::whiteGreenButton.setTexture(Resources::greenUITexture);
		Resources::whiteGreenButton.setTextureRect(sf::IntRect(0, 143, 190, 49));

		Resources::greenLeft.setTexture(Resources::greenUITexture);
		Resources::greenLeft.setTextureRect(sf::IntRect(378, 143, 39, 31));

		Resources::greenRight.setTexture(Resources::greenUITexture);
		Resources::greenRight.setTextureRect(sf::IntRect(339, 143, 39, 31));

		Resources::greenButton.setTexture(Resources::greenUITexture);
		Resources::greenButton.setTextureRect(sf::IntRect(0, 192, 190, 45));

		////
		Resources::whiteBlueBox.setTexture(Resources::blueUITexture);
		Resources::whiteBlueBox.setTextureRect(sf::IntRect(288, 194, 49, 49));

		Resources::blueUp.setTexture(Resources::blueUITexture);
		Resources::blueUp.setTextureRect(sf::IntRect(388, 72, 28, 42));

		Resources::blueDown.setTexture(Resources::blueUITexture);
		Resources::blueDown.setTextureRect(sf::IntRect(416, 72, 28, 42));

		Resources::whiteBlueButton.setTexture(Resources::blueUITexture);
		Resources::whiteBlueButton.setTextureRect(sf::IntRect(0, 143, 190, 49));

		Resources::blueLeft.setTexture(Resources::blueUITexture);
		Resources::blueLeft.setTextureRect(sf::IntRect(339, 143, 39, 31));

		Resources::blueRight.setTexture(Resources::blueUITexture);
		Resources::blueRight.setTextureRect(sf::IntRect(378, 143, 39, 31));

		Resources::blueButton.setTexture(Resources::blueUITexture);
		Resources::blueButton.setTextureRect(sf::IntRect(0, 192, 190, 45));

		Resources::fieldSprite.setTexture(Resources::fieldTexture);
		Resources::wallHit.setBuffer(Resources::wallHitBuffer);
		Resources::paddleHit.setBuffer(Resources::paddleHitBuffer);
		Resources::playerMiss.setBuffer(Resources::playerMissBuffer);
		(Resources::ballSprite).setTexture(Resources::ballTexture);
	}
	else 
	{
		std::cerr << "Failed to load resources" << std::endl;
		abort();
	}
}