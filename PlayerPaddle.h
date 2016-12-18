#pragma once
class Ball;
class PlayerPaddle:public VisibleGameObject
{	

private:
	struct Controls
	{
		Controls(sf::Keyboard::Key aup, sf::Keyboard::Key adown) :up(aup), down(adown) {}
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
	};
	Controls *controls;
	static bool pressingUp;
	static bool pressingDown;
	static sf::Clock reactionClock;
	static float defaultVelocity;
public:
	sf::Text scoreboard;
	static sf::Time reactionTime;
	static float padding;
	int score;
	static VisibleGameObject *ball;
	float currentVelocity;
	PlayerPaddle(const std::string & name, const float & az_index, sf::Sprite *sprite, const float & ax = 0, const float & ay = 0);
	~PlayerPaddle();
	void convertToAI();
	void draw(sf::RenderWindow &window);
	
	void setupControls(sf::Keyboard::Key up, sf::Keyboard::Key down);
	void updateScore(const int & increment);
	void update(const float &elapsedTime);
};