#include "stdafx.h"
#include "Resources.h"
#include "Ball.h"
#include "GameOver.h"
#include "PlayerPaddle.h"
#include "Game.h"


void Ball::reset()
{
	ball_velocity = generateRandomVelocity();
	setPosition(Game::SCREEN_WIDTH / 2 - getWidth() / 2, Game::SCREEN_HEIGHT / 2 - getHeight() / 2);
	timeSinceStartup = 0.0f;
}

Ball::Ball(const std::string & name, const float & az_index, sf::Sprite *sprite, const float & ax, const float & ay):VisibleGameObject(name,az_index,sprite,ax,ay), timeSinceStartup(0)
{
	 ball_velocity = generateRandomVelocity();
	 ballWidth = getWidth();
	 ballHeight = getHeight();
	 player1 = Game::paddle1;
	 player2 = Game::paddle2;
	 paddle1Width = player1 -> getWidth();
	 paddle1Height = player2->getHeight();
	 paddle2Width = player2->getWidth();
	 paddle2Height = player2->getHeight();
}

sf::Vector2f Ball::generateRandomVelocity()
{
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> dist1(0, 200);
	std::uniform_real_distribution<> dist2(100, 200);
	std::uniform_int_distribution<> signDist(0, 10);
	int sign1 = (signDist(e2) % 2 == 0) ? 1 : -1;
	int sign2 = (signDist(e2) % 2 == 0) ? 1 : -1;
	
	return sf::Vector2f(sign1 * dist2(e2),sign2 * dist1(e2));
}

void Ball::update(const float & elapsedTime)
{
	if (timeSinceStartup < 1.5)
	{
		timeSinceStartup += elapsedTime;
		return;
	}

	sf::Vector2f ballPos = getPosition();
	sf::Vector2f player1Pos = player1->getPosition();
	sf::Vector2f player2Pos = player2->getPosition();
	float xDisplacement = 0.0f;
	float yDisplacement = 0.0f;
//If ball is in the left gutter area	
		if (ballPos.x <= paddle1Width)
		{
			//If ball is within paddle1's height
			if (ballPos.y + (ballHeight/ 2) >= player1Pos.y && ballPos.y + (ballHeight/ 2) <= player1Pos.y + paddle1Height)
			{
				Resources::paddleHit.play();
				ball_velocity.x += ball_velocity.x * 0.1; //Increase x velocity
				ball_velocity.x *= -1; //Reflect the ball
				ball_velocity.y += 0.15 * (((PlayerPaddle*)player1) -> currentVelocity); //Add paddle's y velocity to ball		
				xDisplacement = ball_velocity.x * elapsedTime;
				yDisplacement = ball_velocity.y * elapsedTime;
				setPosition(paddle1Width + xDisplacement, ballPos.y + yDisplacement);
				return;
			}
			else
			{
				//Else paddle missed it
				Resources::playerMiss.play();
					((PlayerPaddle*)player2)->updateScore(1);
					if (((PlayerPaddle*)player2)->score >= Game::Settings::winningPoints)
					{
						GameOver::winner.setString("PLAYER 2 WINS");
						
						Game::_gameState = Game::GameState::GameOver;
						return;
					}
				
				
				ball_velocity = generateRandomVelocity();
				setPosition(Game::SCREEN_WIDTH / 2 - ballWidth/ 2, Game::SCREEN_HEIGHT / 2 - ballHeight/ 2);
				return;
			}
		}
	

	
		if (ballPos.x + ballWidth >= Game::SCREEN_WIDTH - 1 - paddle2Width)
		{
			if (ballPos.y + (ballHeight/ 2) >= player2Pos.y && ballPos.y + (ballHeight/ 2) <= player2Pos.y + paddle2Height)
			{
				Resources::paddleHit.play();
				ball_velocity.x += ball_velocity.x * 0.1;
				ball_velocity.x *= -1;
				ball_velocity.y += 0.15 * ((PlayerPaddle*)player2)->currentVelocity;
				xDisplacement = ball_velocity.x * elapsedTime;
				yDisplacement = ball_velocity.y * elapsedTime;
				setPosition(Game::SCREEN_WIDTH - 1 - paddle2Width - ballWidth + xDisplacement, ballPos.y + yDisplacement);
				return;
			}
			else
			{
					Resources::playerMiss.play();
					((PlayerPaddle*)player1)->updateScore(1);
					if (((PlayerPaddle*)player1)->score >= Game::Settings::winningPoints)
					{
						GameOver::winner.setString("PLAYER 1 WINS");
						Game::_gameState = Game::GameState::GameOver;
						return;
					}
				
				ball_velocity = generateRandomVelocity();
				setPosition(Game::SCREEN_WIDTH / 2 - ballWidth/ 2, Game::SCREEN_HEIGHT / 2 - ballHeight/ 2);
				return;
			}
		}
	

	//Collisions with upper and lower walls
	if (ballPos.y <= 0)
	{
		Resources::wallHit.play();
		ball_velocity.y *= -1;
		xDisplacement = ball_velocity.x * elapsedTime;
		yDisplacement = ball_velocity.y * elapsedTime;
		setPosition(ballPos.x + xDisplacement, yDisplacement);
		return;
	}

	else if(ballPos.y + ballHeight >= Game::SCREEN_HEIGHT - 1)
	{

		Resources::wallHit.play();
		ball_velocity.y *= -1;
		xDisplacement = ball_velocity.x * elapsedTime;
		yDisplacement = ball_velocity.y * elapsedTime;
		setPosition(ballPos.x + xDisplacement, (Game::SCREEN_HEIGHT - 1 - ballHeight) + yDisplacement);
		return;
	}

	xDisplacement = ball_velocity.x * elapsedTime;
	yDisplacement = ball_velocity.y * elapsedTime;
	setPosition(ballPos.x + xDisplacement, ballPos.y + yDisplacement);
}



