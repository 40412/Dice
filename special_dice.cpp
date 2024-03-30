#include "special_dice.h"
#include <string>
#include <vector>
using namespace std;

SpecialDice::SpecialDice(const string& color, const int& numFaces) : Dice(color)
{
    // Constructor implementation goes here
    this->color = color;
    this->numFaces = numFaces;
}

void SpecialDice::roll()
{
    int randN = rand() % numFaces + 1;
    face = randN;
}
