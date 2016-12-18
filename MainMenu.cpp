#include "stdafx.h"
#include "Resources.h"
#include "MainMenu.h"
#include "Game.h"

Button MainMenu::AIButton(&Resources::whiteGreenButton, &Resources::whiteBlueButton, &Resources::kenVectorFont,&Resources::mouseOver, &Resources::mouseClick, Game::AIsetup, 525, 238);
Button MainMenu::playButton(&Resources::whiteGreenButton, &Resources::whiteBlueButton, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, Game::multiplayerSetup, 294, 238);
Button MainMenu::incrementDifficultyButton(&Resources::greenRight, &Resources::blueRight, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, Game::Settings::incrementDifficulty, 724,346) ;
Button MainMenu::decrementDifficultyButton(&Resources::greenLeft,&Resources::blueLeft, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, Game::Settings::decrementDifficulty, 481, 346);
Button MainMenu::incrementPointsButton(&Resources::greenUp, &Resources::blueUp, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, Game::Settings::incrementPoints, 323, 339);
Button MainMenu::decrementPointsButton(&Resources::greenDown, &Resources::blueDown, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, Game::Settings::decrementPoints, 416, 339);
Button MainMenu::difficultyDisplay(&Resources::whiteGreenButton, nullptr,  &Resources::kenVectorFont, nullptr, nullptr, nullptr, 528, 334);
Button MainMenu::gamePoints(&Resources::whiteGreenBox,  nullptr, &Resources::kenVectorFont, nullptr, nullptr, nullptr, 358, 334);

Button* (MainMenu::buttons)[] = { &(MainMenu::AIButton), &(MainMenu::playButton), &(MainMenu::incrementDifficultyButton), &(MainMenu::decrementDifficultyButton), &(MainMenu::incrementPointsButton), &(MainMenu::decrementPointsButton)};										   


void MainMenu::setup()
{
	for (Button* b : buttons)
	{
		(b->text).setFillColor(Resources::green);
		b->defaultColor = Resources::green;
		b->hoverColor = Resources::blue;
		(b->text).setCharacterSize(20);
	}
	(difficultyDisplay.text).setFillColor(Resources::green);
	(gamePoints.text).setFillColor(Resources::green);
	difficultyDisplay.text.setCharacterSize(20);
	gamePoints.text.setCharacterSize(20);
	difficultyDisplay.defaultColor = Resources::green;
	difficultyDisplay.hoverColor = Resources::green;
	gamePoints.hoverColor = Resources::green;
		gamePoints.defaultColor = Resources::green;
	AIButton.text.setString("SINGLE PLAYER");
	AIButton.setTextAtCenter();

	
	AIButton.clickableArea = sf::FloatRect(AIButton.x, AIButton.y, AIButton.buttonSprite->getGlobalBounds().width, AIButton.buttonSprite->getGlobalBounds().height);
	playButton.text.setString("MULTI PLAYER");
	playButton.setTextAtCenter();
	playButton.clickableArea = sf::FloatRect(playButton.x, playButton.y, playButton.buttonSprite->getGlobalBounds().width, playButton.buttonSprite->getGlobalBounds().height);
	
	difficultyDisplay.text.setString(Game::Settings::difficulty);
	difficultyDisplay.setTextAtCenter();
	
	incrementDifficultyButton.clickableArea = sf::FloatRect(incrementDifficultyButton.x, incrementDifficultyButton.y, incrementDifficultyButton.buttonSprite->getGlobalBounds().width, incrementDifficultyButton.buttonSprite->getGlobalBounds().height);
	decrementDifficultyButton.clickableArea = sf::FloatRect(decrementDifficultyButton.x, decrementDifficultyButton.y, decrementDifficultyButton.buttonSprite->getGlobalBounds().width, decrementDifficultyButton.buttonSprite->getGlobalBounds().height);
	
	
	gamePoints.text.setString(std::to_string(Game::Settings::winningPoints));
	gamePoints.setTextAtCenter();
	

	incrementPointsButton.clickableArea = sf::FloatRect(incrementPointsButton.x, incrementPointsButton.y, incrementPointsButton.buttonSprite->getGlobalBounds().width, incrementPointsButton.buttonSprite->getGlobalBounds().height);
	decrementPointsButton.clickableArea = sf::FloatRect(decrementPointsButton.x, decrementPointsButton.y, decrementPointsButton.buttonSprite->getGlobalBounds().width, decrementPointsButton.buttonSprite->getGlobalBounds().height);

}




void MainMenu::show(sf::RenderWindow& window)
{
	Resources::homeScreen.setVolume(10);
	Resources::homeScreen.setLoop(true);
	Resources::homeScreen.play();
	sf::Event currentEvent;

	while (Game::_gameState == Game::GameState::ShowingMenu) 
	{
		while ( window.pollEvent(currentEvent))
		{
			for (Button* &button : buttons)
			{
				button->onFocus(sf::Mouse::getPosition(window));
			}

			if (currentEvent.type == sf::Event::MouseButtonPressed)
			{
				for (Button* &button : buttons)
				{
					
					button -> serviceClick(sf::Vector2f((float)currentEvent.mouseButton.x,(float)currentEvent.mouseButton.y));
				}
				
				
				gamePoints.text.setString(std::to_string(Game::Settings::winningPoints));
				difficultyDisplay.text.setString(Game::Settings::difficulty);
				gamePoints.setTextAtCenter();
				difficultyDisplay.setTextAtCenter();
			}
			else if (currentEvent.type == sf::Event::Closed)
			{
				Game::_gameState = Game::GameState::Exiting;
			}
		}

		window.clear();
		window.draw(Resources::backgroundSprite);

		playButton.draw(window);
		AIButton.draw(window);
		decrementDifficultyButton.draw(window);
		incrementDifficultyButton.draw(window);
		difficultyDisplay.draw(window);
		incrementPointsButton.draw(window);
		decrementPointsButton.draw(window);
		gamePoints.draw(window);
		window.display();
	}
	Resources::homeScreen.stop();
}



void Button::setTextAtCenter()
{
	if(currentSprite)
	{
		text.setPosition((x  + (currentSprite->getGlobalBounds().width / 2.0f)) - (text.getGlobalBounds().width / 2.0f), (y + (currentSprite->getGlobalBounds().height / 2.0f)) - (2.0f * (text.getGlobalBounds().height / 2.0f)));
	}
}

void Button::setPosition(const float & x, const float & y)
{
	this->x = x;
	this->y = y;
}

void Button::draw(sf::RenderWindow & window)
{
	currentSprite->setPosition(x, y);
	window.draw(*currentSprite);
	window.draw(text);
}

bool Button::onFocus(sf::Vector2i mousePos)
{

	if (clickableArea.contains(mousePos.x, mousePos.y))
	{

		if (!focus)
		{
			focus = true;
			text.setFillColor(hoverColor);
			if (mouseOver)
			{
				mouseOver->play();
			}
			if (hoverSprite)
			{
				currentSprite = hoverSprite;
			}
		}
	}
	else 
	{
		text.setFillColor(defaultColor);
		if (buttonSprite)
		{
			currentSprite = buttonSprite;
		}
		focus = false;
	}
	return false;
}

bool Button::serviceClick(sf::Vector2f mouseClick)
{
	if (clickableArea.contains(mouseClick) && callback)
	{
		if (this->mouseClick)
		{
			(this->mouseClick)->play();
		}
			callback();
			return true;
	}
	return false;
}
