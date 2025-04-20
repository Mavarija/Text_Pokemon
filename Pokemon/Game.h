#pragma once
#include "Player.h"
#include "Grass.h"

class CGame
{
public:
	// Constructor
	CGame();
	// Method to handle main game loop
	void GameLoop(CPlayer& _player);

private:
	// Members
	SGrass forestGrass;
};

