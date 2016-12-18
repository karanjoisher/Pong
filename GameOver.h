#pragma once
#include "stdafx.h"


struct Button;
class GameOver
{
public:
	static Button quit;
	static Button mainMenu;
	static void setup();
	static void goToMainMenu();
	static void exit();
	static sf::Text winner;
	static void show(sf::RenderWindow &window);
};