#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <memory>
#include "player.h"
#include "dice.h"

using namespace std;

class Game
{
public:
    Game();
    void addPlayer(Player player);
    void addDice(Dice dice);
    void gameLoop();
    void print_players();
    vector<Player> winner() const;
private:
    vector<Player> players;
    vector<Dice> dice;
};

#endif // GAME_H
