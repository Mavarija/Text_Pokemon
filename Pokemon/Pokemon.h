#pragma once
#include "Utility.h"
#include "PokemonEnums.h"
#include "Move.h"
#include <vector>

class CPokemon
{
public:
    // Default constructor
    CPokemon();
    // Parameterized constructor
    CPokemon(string _name, EPokemonType _type, /*int _health,*/ int _maxHealth, int _attackPower, vector<SMove>);
    // Copy constructor
    CPokemon(const CPokemon* _other);
    // Destructor
    ~CPokemon();

    // Method to damage target pokemon
    virtual void Attack(SMove _selectedMove, CPokemon* _target);
    // Method to reduce health
    void TakeDamage(int _damage);
    // Method to check if health is <= 0
    bool IsFainted() const;
    // Method to restore health
    void Heal();
    // Method for selecting moves
    void SelectAndUseMove(CPokemon* _target);
    // Method for reducing dmg
    void ReduceAttackPower(int _reducedDamage);

    // Getters
    int GetHealth();
    string GetName();

    // Vector to store list of moves
    vector<SMove> moves;

protected:
    // Members
    string name;
    EPokemonType type;
    int health;
    int maxHealth;
    int attackPower;

    // Separate methods for each individual task
    void PrintAvailableMoves();
    int SelectMove();
    void UseMove(SMove _selectedMove, CPokemon* _target);

};


