#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
public:
    Player(const string& name);
    string getName() const;
    void setScore(int score);
    int getScore() const;
private:
    string name;
    int score;
};

#endif // PLAYER_H
