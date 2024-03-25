#include <iostream>
#include "player.h"
#include "dice.h"
#include "special_dice.h"
#include <memory>
#include "game.h"

using namespace std;

int main()
{
    int numPlayers;
    unique_ptr<Dice> greenDie = make_unique<Dice>("green", 6);
    greenDie->roll();
    cout << "Die: " << greenDie->getColor() << " " << greenDie->getNumFaces() << " " << greenDie->getFace() << endl;

    SpecialDice twelveSides("red", 12);
    twelveSides.roll();
    Dice yellowDie("yellow", 6);
    cout << twelveSides.getFace() << endl;

    Player p("J");
    Player p2("V");

    Game game;
    game.addPlayer(p);
    game.addPlayer(p2);

    game.print_players();
    game.addDice(twelveSides);
    game.addDice((yellowDie));

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
