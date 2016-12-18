#include "stdafx.h"
#include "Resources.h"
#include "MainMenu.h"
#include "VisibleGameObject.h"
#include "PlayerPaddle.h"
#include "GameOver.h"
#include "Ball.h"
#include "Game.h"


VisibleGameObject *Game::paddle1 = nullptr;
VisibleGameObject *Game::paddle2 = nullptr;
VisibleGameObject *Game::background = nullptr;
VisibleGameObject *Game::ball = nullptr;


Game::GameState Game::_gameState = Uninitialized;
sf::Clock Game::frameClock;
const sf::Time timePerFrame = sf::seconds(1.0f / 24.0f);
sf::Time timeSinceLastUpdate = sf::Time::Zero;
//float Game::deltaTime = 0.0f;

sf::RenderWindow Game::_mainWindow;
int Game::SCREEN_WIDTH = 1000;
int Game::SCREEN_HEIGHT = 500;
GameObjectManager Game::manager;


void Game::setField()
{
	((Ball*)ball)->reset();
	paddle1->setPosition(0, 0);
	paddle2->setPosition(SCREEN_WIDTH - (paddle2->getWidth()), 0);
	((PlayerPaddle*)paddle1)->updateScore(-((PlayerPaddle*)paddle1)->score);
	((PlayerPaddle*)paddle2)->updateScore(-((PlayerPaddle*)paddle2)->score);
}


void Game::AIsetup()
{
	if (Game::Settings::difficulty == "Easy")
	{
		PlayerPaddle::reactionTime = sf::seconds(0.5f);
		PlayerPaddle::padding = 8.0f;
	}
	else if (Game::Settings::difficulty == "Medium")
	{
		PlayerPaddle::reactionTime = sf::seconds(0.25f);
		PlayerPaddle::padding = 2.5f;
	}
	else
	{
		PlayerPaddle::reactionTime = sf::seconds(0.01f);
		PlayerPaddle::padding = 2.5f;
	}
	
	((PlayerPaddle*)paddle1)->convertToAI();
	((PlayerPaddle*)paddle2)->setupControls(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down);
	setField();
	_gameState = Playing;
}

void Game::multiplayerSetup()
{
	((PlayerPaddle*)paddle1)->setupControls(sf::Keyboard::Key::W, sf::Keyboard::Key::S);
	((PlayerPaddle*)paddle2)->setupControls(sf::Keyboard::Key::Up, sf::Keyboard::Key::Down);
	setField();
	_gameState = Playing;
}

void Game::start() {
	
	if (_gameState != Uninitialized) {
		return;
	}

	
	MainMenu::setup();
	GameOver::setup();


	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pong");
	_gameState = ShowingMenu;
	_mainWindow.setFramerateLimit(30);
//	deltaTime = 0.0f;

	//Creating game entities and adding them to manager to handle rendering and updates
	paddle1 = new PlayerPaddle("Player1", 1.0f, &(Resources::paddleSprite));
	paddle2 = new PlayerPaddle("Player2", 1.0f, &(Resources::paddleSprite), 0, 0);

	paddle2->setPosition(SCREEN_WIDTH - (paddle2->getWidth()), 0);
	
	(((PlayerPaddle*)paddle2)->scoreboard).setPosition(SCREEN_WIDTH / 2 + 10, 10);
	(((PlayerPaddle*)paddle2)->scoreboard).setCharacterSize(40);

	(((PlayerPaddle*)paddle1)->scoreboard).setPosition(SCREEN_WIDTH / 2 - 55, 10);
	(((PlayerPaddle*)paddle1)->scoreboard).setCharacterSize(40);
	

	background = new VisibleGameObject("Background", 0.0f, &(Resources::fieldSprite));

	manager.addObject(paddle1);
	manager.addObject(paddle2);
	manager.addObject(background);

	ball = new Ball("Ball", 0.5f, &(Resources::ballSprite), SCREEN_WIDTH / 2 - Resources::ballSprite.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - Resources::ballSprite.getGlobalBounds().height / 2);
	((PlayerPaddle*)paddle1)->ball = ball;
	manager.addObject(ball);


	while (_gameState != Exiting) 
	{	
		timeSinceLastUpdate += frameClock.restart();
		gameLoop();
	}
	_mainWindow.close();
}



void Game::gameLoop()
{
	
	sf::Event currentEvent;
	while (_mainWindow.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Exiting;
		}
	}

	switch (_gameState)
	{
		case ShowingMenu:
		{
			MainMenu::show(_mainWindow);
			frameClock.restart();
			timeSinceLastUpdate = sf::Time::Zero;
			break;
		}
		case GameState::GameOver:
		{
			GameOver::show(_mainWindow);
			break;
		}
		case Playing:
		{
			while (timeSinceLastUpdate > timePerFrame)
			{
				timeSinceLastUpdate -= timePerFrame;
				manager.updateAllLayers(timePerFrame.asSeconds());
			}

			_mainWindow.clear();
			manager.drawAllLayers(_mainWindow);
			_mainWindow.display();
			break;
		}
		default:
			break;
		}
	}
	
	
//Game::Settings

std::vector<std::string> Game::Settings::difficultyOptions = { "Easy", "Medium", "Hard" };
std::string Game::Settings::difficulty = "Easy";
int Game::Settings::winningPoints = 1;
int Game::Settings::minimumPoints= 1;
int Game::Settings::maximumPoints = 10;
int Game::Settings::currentDifficultyIndex =  0;

void Game::Settings::incrementPoints()
{
	if (winningPoints + 1 <= maximumPoints)
	{
		winningPoints++;
	}
}

void Game::Settings::decrementPoints()
{
	if (winningPoints - 1 >= minimumPoints)
	{
		winningPoints--;
	}
}

void Game::Settings::incrementDifficulty()
{
	currentDifficultyIndex = (currentDifficultyIndex + 1) % difficultyOptions.size();
	difficulty = difficultyOptions[currentDifficultyIndex];
}

void Game::Settings::decrementDifficulty()
{
	if (currentDifficultyIndex > 0)
	{
		currentDifficultyIndex--;
	}
	else
	{
		currentDifficultyIndex = difficultyOptions.size() - 1;
	}
		difficulty = difficultyOptions[currentDifficultyIndex];
}
