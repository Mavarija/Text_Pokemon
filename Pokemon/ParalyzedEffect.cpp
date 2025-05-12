#include "ParalyzedEffect.h"

void CParalyzedEffect::ApplyEffect(CPokemon* _target)
{
	std::cout << _target->GetName() << " is paralyzed! It may not be able to move!\n";

	// Effect lasts between 1 and 3 turns randomly
	turnsLeft = rand() % 3 + 1;
}

string CParalyzedEffect::GetEffectName()
{
	return "Paralyzed";
}

bool CParalyzedEffect::TurnEndEffect(CPokemon* _target)
{
	if (turnsLeft <= 0)
	{
		ClearEffect(_target);
		return true; // Can move as the effect is cleared
	}
	turnsLeft--;

	// Generate a number between 0 and 3
	int paralysisChance = rand() % 4;
	
	// 25% chance that the Pokemon cannot move due to paralysis
	if (paralysisChance == 0)
	{
		std::cout << _target->GetName() << " is paralyzed! It can't move!\n";
		return false; // Pokemon cannot act this turn
	}
	
	// Otherwise, it can act normally
	std::cout << _target->GetName() << " shakes off the paralysis momentarily and can move!\n";
	return true; // Pokemon can act this turn
}

void CParalyzedEffect::ClearEffect(CPokemon* _target)
{
	std::cout << _target->GetName() << " is no longer paralyzed!\n";
	_target->ClearEffect();
}
