#include "Pokemon.h"

// Consturctors and Destructor
CPokemon::CPokemon()
    : name("Unknown"), type(EPokemonType::EPT_Normal),
      health(50), maxHealth(50), attackPower(10)
{
}
CPokemon::CPokemon(string _name, EPokemonType _type, /*int _health,*/ int _maxHealth, int _attackPower, vector<SMove> _moves)
    : name(_name), type(_type), health(_maxHealth), maxHealth(_maxHealth), attackPower(_attackPower), moves(_moves)
{
}
CPokemon::CPokemon(const CPokemon* _other)
{
    name = _other->name;
    type = _other->type;
    health = _other->health;
    maxHealth = _other->maxHealth;
    attackPower = _other->attackPower;
    moves = _other->moves;
}
CPokemon::~CPokemon()
{
}

// Method to damage target pokemon
void CPokemon::Attack(SMove _selectedMove, CPokemon* _target)
{
    _target->TakeDamage(_selectedMove.power);
}

// Method to reduce health
void CPokemon::TakeDamage(int _damage)
{
    health -= _damage;
    if (health < 0)
    {
        health = 0;
    }
}

// Method to check if health is <= 0
bool CPokemon::IsFainted() const
{
    if (health <= 0)
    {
        return true;
    }
    // return health <= 0;
}

// Method to restore health
void CPokemon::Heal()
{
    // Restore health to full
    health = maxHealth;
}

// Getters
int CPokemon::GetHealth()
{
    return health;
}
string CPokemon::GetName()
{
    return name;
}

void CPokemon::SelectAndUseMove(CPokemon* _target)
{
    // Show all available moves
    PrintAvailableMoves();

    // Input player's choice
    int choice = SelectMove();
    SMove selectedMove = moves[choice - 1];
    
    // Execute the move
    UseMove(selectedMove, _target);
}

void CPokemon::ReduceAttackPower(int _reducedDamage)
{
    for (int i = 0; i < moves.size(); i++)
    {
        moves[i].power -= _reducedDamage;
        if (moves[i].power < 0)
        {
            moves[i].power = 0;
        }
    }
}

bool CPokemon::CanAttack()
{
    if (appliedEffect == nullptr)
    {
        return true;
    }
    else
    {
        return appliedEffect->TurnEndEffect(this);
    }
}

bool CPokemon::CanApplyEffect()
{
    return appliedEffect == nullptr;
}

void CPokemon::ApplyEffect(EStatusEffectType _effectToApply)
{
    switch (_effectToApply)
    {
    case EStatusEffectType::SET_Paralyzed:
        appliedEffect = new CParalyzedEffect();
        appliedEffect->ApplyEffect(this);
        break;
    default:
        appliedEffect = nullptr;
    }
}

void CPokemon::ClearEffect()
{
    appliedEffect = nullptr;
}

void CPokemon::PrintAvailableMoves()
{
    cout << name << "'s available moves:\n";
    
    // List out all moves for the player to choose from
    for (size_t i = 0; i < moves.size(); ++i)
    {
        cout << i + 1 << ": " << moves[i].name << "(Power: " << moves[i].power << ")\n";
    }
}

int CPokemon::SelectMove()
{
    // Ask player to select a move
    int choice;
    cout << "Choose a move: ";
    cin >> choice;

    // Validate the choice
    while (choice < 1 || choice > static_cast<int>(moves.size()))
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}

void CPokemon::UseMove(SMove _selectedMove, CPokemon* _target)
{
    cout << name << " used " << _selectedMove.name << "!\n";
    Attack(_selectedMove, _target);

    Utility::WaitForEnter();

    if (_target->IsFainted())
    {
        cout << _target->name << " fainted!\n";
    }
    else
    {
        cout << _target->name << " has " << _target->health << " HP left.\n";
    }
}
