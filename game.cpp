#include "game.h"
#include "dice.h"
#include "special_dice.h"
#include <vector>
#include <iostream>
#include <memory>

//using namespace std;

Game::Game()
{
    available_dice.emplace_back(std::make_unique<Dice>("green"));
    available_dice.emplace_back(std::make_unique<SpecialDice>("red", 12));
    available_dice.emplace_back(std::make_unique<SpecialDice>("blue", 24));
}

void Game::initialize_game()
{
    string input;
    int num_green;
    int num_blue;
    int num_red;

    players.clear();
    dice.clear();

    while(true)
    {
        cout << "Add new player or (c) to continue" << endl << "Player name:";
        cin >> input;

        if (input == "c")
        {
            break;
        }
        else
        {
            Player player(input);
            addPlayer(player);
        }
    }

    cout << "Choose dice" << endl;
    cout << "How many green dice? (0-3)" << endl;
    cin >> num_green;

    if(cin.fail())
    {
        cin.clear();
        cout << "Invalid number. Using 1 die;\n";
        num_green = 1;
    }

    cout << "How many blue dice? (0-3)" << endl;
    cin >> num_blue;

    if(cin.fail())
    {
        cin.clear();
        cout << "Invalid number. Using 1 die;\n";
        num_blue = 1;
    }
    cout << "How many red dice? (0-3)" << endl;
    cin >> num_red;

    if(cin.fail())
    {
        cin.clear();
        cout << "Invalid number. Using 1 die;\n";
        num_red = 1;
    }

    for (int g = 0; g < num_green; g++)
    {
        dice.emplace_back(std::make_unique<Dice>("green"));
    }

    for (int b = 0; b < num_blue; b++)
    {
        dice.emplace_back(std::make_unique<SpecialDice>("blue", 24));
    }

    for (int r = 0; r < num_red; r++)
    {
        dice.emplace_back(std::make_unique<SpecialDice>("red", 12));
    }

    if (num_blue == 0 && num_green == 0 && num_red == 0)
    {
        cout << "No dice chosen!" << endl;
    }
    else
    {
        cout << "Starting game" << endl;
        gameLoop();
    }

}

void Game::addPlayer(Player player)
{
    players.push_back(player);
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
            players[i].setScore(0);
            string roll_dice;
            cout << "Player " << players[i].getName() << " rolls" << endl;
            cin >> roll_dice;
            int score = players[i].getScore();

            for(int j = 0; j < dice.size(); j++)
            {
                dice[j]->roll();
                int roll = dice[j]->getFace();
                cout << dice[j]->getColor() << ":" << roll << endl;
                score += roll;
                players[i].setScore(score);
            }
            cout << "Score: " << score << endl;
        }

        vector winner = this->winner();
        cout << "Winner:" << endl;

        for (int i = 0; i < winner.size(); i++)
        {
            cout << winner[i].getName() << endl;
        }

        cout << "With score:" << winner[0].getScore() << endl;

        cout << "Enter 'b' to set a new game or quit or any other input to play again" << endl;
        cin >> input;

        if (input == "b")
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

    for (int i = 0; i < players.size(); i++)
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
