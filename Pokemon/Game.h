#pragma once
#include "Player.h"
#include "Grass.h"

class CGame
{
public:
	// Constructor
	CGame();
	// Destructor
	~CGame();

	// Method to handle main game loop
	void GameLoop(CPlayer* _player);
	// Method for visiting poke center
	void VisitPokeCenter(CPlayer* _player);

private:
	// Members
	SGrass forestGrass;
	CPokemon* wildPokemon;
};

