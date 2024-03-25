#include "game.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

Game::Game()
{

}

void Game::addPlayer(Player player)
{
    players.push_back(player);
}

void Game::addDice(Dice dice)
{
    this->dice.push_back(dice);
}

void Game::print_players()
{
    for(int i = 0; i < players.size(); i++)
    {
        cout << players[i].getName() << endl;
    }
}

void Game::gameLoop()
{
    string input;

    while (true)
    {
        cout << "Continue game?" << endl;
        cin >> input;

        if (input == "q")
        {
            break;
        }

        for(int i = 0; i < players.size(); i++)
        {
            cout << "Player " << players[i].getName() << " rolls" << endl;

            for(int i = 0; i < dice.size(); i++)
            {
                dice[i].roll();
                int roll = dice[i].getFace();
                cout << "rolled: " << roll << endl;
                int score = players[i].getScore();
                score += roll;
                players[i].setScore(score);
                cout << "Score now: " << score << endl;
            }
        }
    }
}
