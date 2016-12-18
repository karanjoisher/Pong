#include "stdafx.h"
#include"Resources.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Resources::load();
	Game::start();
	return 0;
}