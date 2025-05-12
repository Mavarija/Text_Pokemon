#pragma once
#include "Utility.h"
#include "Pokemon.h"

class IStatusEffect
{
public:
	// Apply the effect (e.g. poison, burn)
	virtual void ApplyEffect(CPokemon* _target) = 0;

	// Get the name of the effect
	virtual string GetEffectName() = 0;

	// Apply the changes due to effect after the end of each turn
	// Returns true if the Pokemon can move, else false
	virtual bool TurnEndEffect(CPokemon* _target) = 0;

	// Remove effect
	virtual void ClearEffect(CPokemon* _target) = 0;

	// Destructor
	virtual ~IStatusEffect() = default;
};