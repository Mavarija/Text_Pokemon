#include "Caterpie.h"

// Constructor initialized with CPokemon custom constructor
CCaterpie::CCaterpie()
	: CPokemon("Caterpie", EPokemonType::EPT_Bug, 100, 10,
		{SMove("BUG BITE", 25), SMove("STICKY WEB", 10)})
{
}

// Caterpie method
void CCaterpie::BugBite(CPokemon* _target)
{
	cout << name << " uses Bug Bite on " << _target->GetName() << "!\n";
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
void CCaterpie::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "STICKY WEB")
	{
		// Reduce the target's next attack damage (for simplicity, reducing by a fixed val)
		int reducedDamage = 5;
		_target->ReduceAttackPower(reducedDamage);
		std::cout << _target->GetName() << "'s next attack will be reduced by " << reducedDamage << " damage!\n";
	}
/*
	SelectAndUseMove(_target);
	BugBite(_target);
*/
}
