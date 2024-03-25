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
        for(int i = 0; i < players.size(); i++)
        {
            cout << "Player " << players[i].getName() << " rolls" << endl;
            int score = players[i].getScore();

            for(int j = 0; j < dice.size(); j++)
            {
                dice[i].roll();
                int roll = dice[i].getFace();
                cout << "rolled: " << roll << endl;

                cout << score << endl;
                score += roll;
                players[i].setScore(score);
                cout << "Score now: " << score << endl;
            }
        }
        cout << "Continue game?" << endl;
        cin >> input;

        if (input == "q")
        {
            break;
        }
    }
}

vector<Player> Game::winner() const
{
    vector<Player> winners;
    int score;
    int max_score = 0;

    for (i = 0; i < players.size(); i++)
    {
        score = players[i].getScore();

        if (score > max_score)
        {
            max_score = score;
            winners.clear();
            winners.push_back(players[i]);
        }
        else if (score == max_score)
        {
            winners.push_back(players[i]);
        }
    }
    return winners;
}
