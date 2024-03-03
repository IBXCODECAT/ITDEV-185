#include "Coin.h"
#include <cstdlib>
#include <ctime>

double Coin::balance = 0.0;

Coin::Coin(double val) : value(val) {
    srand(time(0));
    toss();
}

void Coin::toss() {
    if (rand() % 2 == 0) {
        sideUp = "HEADS";
        heads = true;
    }
    else {
        sideUp = "tails";
        heads = false;
    }
}

void Coin::addBalance() {
    balance += value;
}

double Coin::getBalance() {
    return balance;
}

bool Coin::getHeads() {
    return heads;
}

double Coin::getValue() {
    return value;
}

std::string Coin::getSideUp() {
    return sideUp;
}
