#pragma once
#include "GameObjectManager.h"
class Game {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	static VisibleGameObject *paddle1;
	static VisibleGameObject *paddle2;
	static VisibleGameObject *background;
	static VisibleGameObject *ball;

	static void multiplayerSetup();
	static void AIsetup();

	static void start();
	static sf::RenderWindow _mainWindow;
	
	struct Settings
	{
		static std::vector<std::string> difficultyOptions;
		static std::string difficulty;
		static int winningPoints;
		static int maximumPoints;
		static 	int minimumPoints;
		static void incrementPoints();
		static void decrementDifficulty();
		static void decrementPoints();
		static void incrementDifficulty();
	private:
		static int currentDifficultyIndex;
	};


	//static float deltaTime;
	static sf::Clock frameClock;
	static GameObjectManager manager;
	enum GameState {Uninitialized, ShowingMenu, Playing, GameOver, Exiting};
	static GameState _gameState;
private:
	static void setField();
	static void gameLoop();
};


