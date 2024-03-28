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
    Game game;
    seedRand();
    string input;

    while (true)
    {
        game.initialize_game();
        cout << "Enter 'q' to quit game or anything else to set new game" << endl;
        cin >> input;

        if (input == "q")
        {
            break;
        }
    }


    return 0;
}
