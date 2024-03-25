#include "player.h"

Player::Player(const std::string& name) : name(name), score(0)
{
    // Constructor implementation
}

std::string Player::getName() const
{
    return name;
}

void Player::setScore(int score)
{
    this->score = score;
}

int Player::getScore() const
{
    return score;
}
