#include "Pidgey.h"
#include "BattleManager.h"

// Constructor initialized with CPokemon custom constructor
CPidgey::CPidgey()
	: CPokemon("Pidgey", EPokemonType::EPT_Normal, 100, 35,
		{SMove("WING ATTACK", 25), SMove("GUST", 15)})
{
}

// Pidgey method
void CPidgey::WingAttack(CPokemon* _target)
{
	cout << name << " uses Wing Attack on " << _target->GetName() << "!\n";
	Utility::WaitForEnter();

	cout << "...\n";

	_target->TakeDamage(20);

	if (_target->IsFainted())
	{
		cout << _target->GetName() << " fainted!\n";
	}
	else
	{
		cout << _target->GetName() << " has " << _target->GetHealth() << " HP left.\n";
	}
	Utility::WaitForEnter();
}

// Base class attack method override
void CPidgey::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "GUST")
	{
		// 20% chance to blow the opponent away
		if (rand() % 100 < 20)
		{
			std::cout << "... and blew the opponent away!\n";
			CBattleManager::StopBattle();
			Utility::WaitForEnter();
		}
	}
/*
	SelectAndUseMove(_target);
	WingAttack(_target);
*/
}