#ifndef DICE_H
#define DICE_H

#include <string>
using namespace std;

class Dice
{
public:
    Dice(const string& color);
    string getColor() const;
    int getNumFaces() const;
    int getFace() const;
    virtual void roll();
protected:
    string color;
    int numFaces;
    int face;
};

#endif // DICE_H


