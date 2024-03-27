#include <iostream>
#include <memory>
#include <ctime>

#include "player.h"
#include "dice.h"
#include "special_dice.h"
#include "game.h"


void seedRand() {
    srand(time(NULL));
}

int main()
{
    unique_ptr<Dice> greenDie = make_unique<Dice>("green");
    greenDie->roll();
    //cout << "Die: " << greenDie->getColor() << " " << greenDie->getNumFaces() << " " << greenDie->getFace() << endl;

    SpecialDice twelveSides("red", 12);
    Dice yellowDie("yellow");

    Player p("J");
    Player p2("V");

    Game game;

    game.addPlayer(p);
    game.addPlayer(p2);

    game.print_players();
    game.addDice(twelveSides);
    game.addDice((yellowDie));

    seedRand();

    while (true)
    {
        cout << "Enter 'q' to quit game" << endl;
        string input;
        cin >> input;

        if (input == "q")
        {
            break;
        }

        game.gameLoop();
    }
    return 0;
}
