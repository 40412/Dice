#ifndef SPECIAL_DICE_H
#define SPECIAL_DICE_H

#include "dice.h"
#include <vector>

class SpecialDice : public Dice
{
public:
    SpecialDice(const string& color, const int& numFaces);
    void roll() override;
private:
};

#endif // SPECIAL_DICE_H




