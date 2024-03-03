#include "Player.h"

Player::Player(int number) : playerNumber(number), sumOfDice(0) {}

void Player::play() {
    sumOfDice = 0;
    for (int i = 0; i < 20; ++i) {
        dice[i].roll();
        sumOfDice += dice[i].getValue();
    }
}

int Player::getNumberOfDice() {
    return 20;
}

int Player::getPlayerNumber() {
    return playerNumber;
}

int Player::getSingleDieValue(int index) {
    return dice[index].getValue();
}

int Player::getSumOfDice() {
    return sumOfDice;
}

void Player::setPlayerNumber(int number) {
    playerNumber = number;
}
