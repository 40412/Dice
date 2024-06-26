#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <memory>
#include "player.h"
#include "dice.h"

class Game
{
public:
    Game();
    void addPlayer(Player player);
    void initialize_game();
    void gameLoop();
    void print_players();
    vector<Player> winner() const;
private:
    vector<Player> players;
    vector<unique_ptr<Dice>> dice;
};

#endif // GAME_H
