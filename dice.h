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
    int getFace() const;
    void roll();
protected:
    string color;
    int numFaces;
    int face;
};

#endif // DICE_H


