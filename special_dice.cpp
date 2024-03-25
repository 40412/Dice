#include "special_dice.h"
#include <string>
#include <vector>
using namespace std;

SpecialDice::SpecialDice(const string& color, const int& numFaces) : Dice(color, numFaces)
{
    // Constructor implementation goes here
    this->color = color;
    this->numFaces = numFaces;

    for(int i = 1; i <= numFaces; i++)
    {
        faces.push_back(i);
    }
}

const vector<int>& SpecialDice::getFaces() const
{
    return faces;
}

void SpecialDice::roll()
{
    srand(time(NULL));
    int randN = rand() % numFaces + 1;
    face = randN;
}
