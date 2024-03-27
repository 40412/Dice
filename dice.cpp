#include "dice.h"
#include <string>
#include <iostream>
using namespace std;

Dice::Dice(const string& color)
{
    this->color = color;
    this->numFaces = 6;
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
    int randN = rand() % 6 + 1;
    face = randN;
}
