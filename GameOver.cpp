#include"stdafx.h"
#include "Resources.h"
#include "Game.h"
#include "MainMenu.h"
#include "GameOver.h"

sf::Text GameOver::winner;
Button GameOver::quit(&Resources::whiteGreenButton, &Resources::whiteBlueButton, &Resources::kenVectorFont,&Resources::mouseOver,&Resources::mouseClick, exit, 499+10, 280);
Button GameOver::mainMenu(&Resources::whiteGreenButton, &Resources::whiteBlueButton, &Resources::kenVectorFont, &Resources::mouseOver, &Resources::mouseClick, goToMainMenu, 499-190-10,280);

void GameOver::setup()
{
	winner.setCharacterSize(20);
	quit.text.setCharacterSize(20);
	mainMenu.text.setCharacterSize(20);
	quit.text.setFillColor(Resources::green);
    mainMenu.text.setFillColor(Resources::green);
	quit.defaultColor = (Resources::green);
	quit.hoverColor = Resources::blue;
	mainMenu.defaultColor = (Resources::green);
	mainMenu.hoverColor = Resources::blue;

	winner.setFont(Resources::kenVectorFont);
	winner.setFillColor(Resources::purple);
	
	quit.text.setString("QUIT");
	quit.setTextAtCenter();
	quit.clickableArea = sf::FloatRect(quit.x, quit.y, quit.buttonSprite->getGlobalBounds().width, quit.buttonSprite->getGlobalBounds().height);

	mainMenu.text.setString("MainMenu");
	mainMenu.setTextAtCenter();
	mainMenu.clickableArea = sf::FloatRect(mainMenu.x, mainMenu.y, mainMenu.buttonSprite->getGlobalBounds().width, mainMenu.buttonSprite->getGlobalBounds().height);
}

void GameOver::goToMainMenu()
{
	Game::_gameState = Game::GameState::ShowingMenu;
}

void GameOver::exit()
{
	Game::_gameState = Game::GameState::Exiting;
}

void GameOver::show(sf::RenderWindow &window)
{
	sf::Event currentEvent;
	winner.setPosition(Game::SCREEN_WIDTH / 2 - winner.getGlobalBounds().width / 2, Game::SCREEN_HEIGHT / 2 - winner.getGlobalBounds().height / 2);
	while (Game::_gameState == Game::GameState::GameOver)
	{
		while (window.pollEvent(currentEvent))
		{
			quit.onFocus(sf::Mouse::getPosition(window));
			mainMenu.onFocus(sf::Mouse::getPosition(window));
			if (currentEvent.type == sf::Event::MouseButtonPressed)
			{
				quit.serviceClick(sf::Vector2f(currentEvent.mouseButton.x, currentEvent.mouseButton.y));
				mainMenu.serviceClick(sf::Vector2f(currentEvent.mouseButton.x, currentEvent.mouseButton.y));
			}
		}


		window.clear();
		Game::manager.drawAllLayers(window);
		mainMenu.draw(window);
		quit.draw(window);
		window.draw(winner);
		window.display();
	}
}
