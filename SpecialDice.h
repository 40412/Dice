#ifndef SPECIALDICE_H
#define SPECIALDICE_H

#include "Dice.h"
#include <vector>

class SpecialDice : public Dice
{
public:
    SpecialDice(const string& color, const int& numFaces);
    const vector<int>& getFaces() const;
private:
    vector<int> faces;
};

#endif // SPECIALDICE_H




