#ifndef DICE_H
#define DICE_H

#include <string>
using namespace std;

class Dice
{
public:
    Dice(const string& color, const int& numFaces);
    string getColor() const;
    int getNumFaces() const;
protected:
    string color;
    int numFaces;
};

#endif // DICE_H


