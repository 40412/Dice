#include "game.h"
#include "dice.h"
#include "special_dice.h"
#include <vector>
#include <iostream>
#include <memory>
#include <limits>

//using namespace std;

Game::Game()
{
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
        cout << "Add new player or (c) to continue to choose dice" << endl << "Player name:";
        cin >> input;

        if (input == "c")
        {
            if (players.size() > 0)
            {
                break;
            }
            else
            {
                cout << "Add at least one player\n";
            }
        }
        else
        {
            Player player(input);
            addPlayer(player);
        }
    }

    cout << "Choose dice for the game" << endl;
    cout << "Green die is a normal die with 6 sides. Choose 0 to 3 green dice:" << endl;
    cin >> num_green;

    if(cin.fail() || num_green > 3 || num_green < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Using 1 die\n";
        num_green = 1;
    }

    cout << "Blue die is a special die with 24 sides. Choose 0 to 3 blue dice:" << endl;
    cin >> num_blue;

    if(cin.fail() || num_blue > 3 || num_blue < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid number. Using 1 die;\n";
        num_blue = 1;
    }
    cout << "Red die is a special die with 12 sides. Choose 0 to 3 red dice:" << endl;
    cin >> num_red;

    if(cin.fail() || num_red > 3 || num_red < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            cout << "Player " << players[i].getName() << " rolls. Roll by typing any input" << endl;
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

        cout << "Enter 'b' to go back to game settings. To play again type any other input" << endl;
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
