#pragma once
#include "Utility.h"
#include "Player.h"
#include "Pokemon.h"

class CProfessorOak
{
public:
	// Members
	string name;

	// Parameterized constructor
	CProfessorOak(string _name);

	// Method to greet player
	void GreetPlayer(CPlayer& _player);
	// Method to offer Pokemon choice to player
	void OfferPokemonChoices(CPlayer& _player);
	// Method to explain quest
	void ExplainMainQuest(CPlayer& _player);
	// Method to handle main game loop
	void GameLoop(CPlayer& _player);
};

