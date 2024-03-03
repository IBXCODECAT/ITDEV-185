// Nathan Schmitt
// ITDEV-185
// Assignment 7

#include <iostream>
#include "Quarter.h"
#include "Dime.h"
#include "Nickel.h"

void evaluateToss(Coin* coin) {
    coin->toss();
    if (coin->getHeads()) {
        coin->addBalance();
        std::cout << "You got heads! $" << coin->getValue() << " has been added to your balance." << std::endl;
    }
    else {
        std::cout << "You got tails! No change to your balance." << std::endl;
    }
}

int main() {
    Quarter quarter;
    Dime dime;
    Nickel nickel;

    //The game is played while the current balance is less than $1
    while (Coin::getBalance() < 1.0) {
        std::cout << "Current balance: $" << Coin::getBalance() << std::endl << std::endl;

        std::cout << "Tossing quarter: " << std::endl;
        evaluateToss(&quarter);
        std::cout << "Tossing dime: " << std::endl;
        evaluateToss(&dime);
        std::cout << "Tossing nickel: " << std::endl;
        evaluateToss(&nickel);
    }

    std::cout << std::endl;

    if (Coin::getBalance() == 1.0) {
        std::cout << "Your total balance is $1. You win the game!" << std::endl;
    }
    else {
        std::cout << "Your total balance is not $1. You lose the game!" << std::endl;
    }

    return 0;
}
