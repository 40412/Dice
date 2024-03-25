#include "dice.h"
#include <string>
#include <iostream>
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

int Dice::getFace() const
{
    return face;
}

void Dice::roll()
{
    srand(time(NULL));
    int randN = rand() % 6 + 1;
    face = randN;
}
