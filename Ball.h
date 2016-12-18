#pragma onceb
#include "stdafx.h"
#include "VisibleGameObject.h"

class Ball :public VisibleGameObject
{
public:

	void reset();
	Ball(const std::string & name, const float & az_index, sf::Sprite *sprite = nullptr, const float & ax = 0, const float & ay = 0);
	sf::Vector2f generateRandomVelocity();
	void update(const float &elapsedTime);
private:
	sf::Vector2f ball_velocity;
	float timeSinceStartup; //Used to pause game at start so players have time to gett ready
	float ballWidth;
	float ballHeight;
	float paddle1Width;
	float paddle2Width;
	float paddle2Height;
	float paddle1Height;
	
	VisibleGameObject *player1;
	VisibleGameObject *player2;
};