#include <iostream>
using namespace std;

int main() {
    
    // variables
    string playerName{};
    int pokeChoice{};

    // intro message
    cout << "Professor Oak: Hello there! Welcome to the world of Pokemon!\n";
    cout << "Professor Oak: My name is Oak. People call me the Pokemon Professor!\n";
    cout << "Professor Oak: But enough about me. Let's talk about you!\n";

    // player input
    cout << "Professor Oak: First, tell me, what's your name?\n\n";
    cin >> playerName;
    cout << "\n";
    cout << "Professor Oak: Ah, " << playerName << "! What a fantastic name!\n";
    cout << "Professor Oak: You must be eager to start your adventure. But first, you'll need a Pokemon of your own!\n";

    // pokemon choices
    cout << "Professor Oak: I have three Pokemon here with me. They're all quite feisty!\n";
    cout << "Professor Oak: Choose wisely...\n\n";
    cout << "1. Charmander - The fire type. A real hothead!\n";
    cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
    cout << "3. Squirtle - The water type. Cool as a cucumber!\n\n";

    cout << "Professor Oak: So, which one will it be? Enter the number of your choice: ";
    cin >> pokeChoice;

    // choice logic
    if (pokeChoice == 1)
    {
        cout << "Professor Oak: A fiery choice! Charmander is yours!\n";
        pokeChoice = 1;
    }
    else if (pokeChoice == 2)
    {
        cout << "Professor Oak: A fine choice! Bulbasaur is always ready to grow on you!\n";
        pokeChoice = 2;
    }
    else if (pokeChoice == 3)
    {
        cout << "Professor Oak: Splendid! Squirtle will keep you cool under pressure!\n";
        pokeChoice = 3;
    }
    else
    {
        cout << "Professor Oak: Hmm, that doesn't seem right. Let me choose for you...\n";

        // select Chairmander if invalid choice
        pokeChoice = 1;
        cout << "Professor Oak: Just kidding! Let's go with Charmander, the fiery dragon in the making!\n";
    }

    return 0;
}
