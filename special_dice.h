#ifndef SPECIAL_DICE_H
#define SPECIAL_DICE_H

#include "dice.h"
#include <vector>

class SpecialDice : public Dice
{
public:
    SpecialDice(const string& color, const int& numFaces);
    const vector<int>& getFaces() const;
    void roll();
private:
    vector<int> faces;
};

#endif // SPECIAL_DICE_H




