#pragma once
#include "Player.h"

class CGame
{
public:
	// Constructor
	CGame();
	// Method to handle main game loop
	void GameLoop(CPlayer& _player);
};

