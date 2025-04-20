#include "Utility.h"
#include "Pokemon.h"
#include "Player.h"
#include "ProfessorOak.h"
#include "Game.h"

int main()
{
    // Create objects
    CProfessorOak professor("Professor Oak");
    CPokemon charmander("Charmander", EPokemonType::EPT_Fire, 100);
    CPlayer player("Ash", charmander);
    CGame game;

    // Greet player, Pokemon choice, main quest, game loop
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);
    professor.ExplainMainQuest(player);
    game.GameLoop(player);

    return 0;
}
