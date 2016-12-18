#include"stdafx.h"
#include "VisibleGameObject.h"
#include "PlayerPaddle.h"
#include "Resources.h"
#include "Game.h"


float PlayerPaddle::padding = 1.25;
VisibleGameObject *PlayerPaddle::ball = nullptr;
float PlayerPaddle::defaultVelocity = 350.0f;
sf::Time PlayerPaddle::reactionTime = sf::seconds(0.025f);
sf::Clock PlayerPaddle::reactionClock;
bool PlayerPaddle::pressingUp = false;
bool PlayerPaddle::pressingDown = false;

PlayerPaddle::PlayerPaddle(const std::string & name, const float & az_index, sf::Sprite *sprite, const float &ax, const float &ay): VisibleGameObject(name, az_index,sprite,ax,ay), controls(nullptr),score(0), currentVelocity(0)
{
	scoreboard.setFillColor(Resources::purple);
	scoreboard.setFont(Resources::kenVectorFont);
	scoreboard.setString(std::to_string(score));
}


PlayerPaddle::~PlayerPaddle()
{
	if (controls)
	{
		delete controls;
	}
}


void PlayerPaddle::convertToAI()
{
	if (controls)
	{
		delete controls;
		controls = nullptr;
	}
}

void PlayerPaddle::draw(sf::RenderWindow & window)
{
	VisibleGameObject::draw(window);
	window.draw(scoreboard);
}



void PlayerPaddle::setupControls(sf::Keyboard::Key up, sf::Keyboard::Key down)
{
	if (controls)
	{
		delete controls;
	}

	controls = new Controls(up, down);
}

void PlayerPaddle::updateScore(const int &increment)
{
	score += increment;
	scoreboard.setString(std::to_string(score));
}

void PlayerPaddle::update(const float & elapsedTime)
{
	sf::Vector2f currentPos = getPosition();
	
	float displacement = 0.0f;
	
	
	if (controls)
	{
		if (sf::Keyboard::isKeyPressed(controls -> up))
		{
			currentVelocity = -defaultVelocity;
		}
		else if (sf::Keyboard::isKeyPressed(controls -> down))
		{
			currentVelocity = defaultVelocity;
		}
		else 
		{
			currentVelocity = 0;
		}

	}
	// AI MODE
	else 
	{
		sf::Vector2f ballPos = ball->getPosition();
		float ballHeight = ball->getHeight();

		if (reactionClock.getElapsedTime() > reactionTime)
		{
			if ((currentPos.y + (getHeight() / 2.0f) < ballPos.y + (ballHeight / 2.0f) - padding))
			{
				currentVelocity = defaultVelocity;
			}
			else if ((currentPos.y + (getHeight() / 2.0f) > ballPos.y + (ballHeight / 2.0f) + padding))
			{
				currentVelocity = -defaultVelocity;
			}
			else
			{
				currentVelocity = 0;
			}
			reactionClock.restart();
		}
	}

	displacement = currentVelocity * elapsedTime;
	if (displacement + currentPos.y < 0.0f)
	{
		setPosition(currentPos.x, 0.0f);
		currentVelocity = 0;
		return;
	}
	else if (displacement + currentPos.y + getHeight() > Game::SCREEN_HEIGHT)
	{
		setPosition(currentPos.x, Game::SCREEN_HEIGHT - getHeight());
		currentVelocity = 0;
		return;
	}

	setPosition(currentPos.x, currentPos.y + displacement);
}
