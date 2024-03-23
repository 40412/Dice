#include <iostream>
#include "Player.h"
#include "Dice.h"
#include "SpecialDice.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Player player1("Jasmin");
    cout << player1.getName() << endl;
    int numPlayers;
    Dice greenDie("green", 6);
    cout << "Die: " << greenDie.getColor() << " " << greenDie.getNumFaces() << endl;

    SpecialDice twelveSides("red", 12);
    for(int face : twelveSides.getFaces())
    {
        cout << face << " ";
    }

    while (true)
    {
        cout << "Enter 'q' to quit game" << endl;
        string input;
        cout << "How many players are playing?";
        cin >> input;

        if (input == "q")
        {
            break;
        }
        numPlayers = stoi(input);
        cout << "number of players is set to: " << numPlayers << endl;
    }
    return 0;
}
