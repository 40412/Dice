#include "Dice.h"
#include <string>
using namespace std;

Dice::Dice(const string& color, const int& numFaces)
{
    this->color = color;
    this->numFaces = numFaces;
}

string Dice::getColor() const
{
    return color;
}

int Dice::getNumFaces() const
{
    return numFaces;
}
