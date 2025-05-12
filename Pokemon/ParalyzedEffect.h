#pragma once
#include "IStatusEffect.h"

class CParalyzedEffect : public IStatusEffect
{
public:
	// Overriding base virtual functions
	void ApplyEffect(CPokemon* _target) override;
	string GetEffectName() override;
	bool TurnEndEffect(CPokemon* _target) override;
	void ClearEffect(CPokemon* _target) override;

private:
	// Track the remaining turns for the effect
	int turnsLeft;
};

