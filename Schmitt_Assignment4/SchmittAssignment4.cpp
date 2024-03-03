#include <iostream>
#include <cstdlib>
#include <ctime>

/// <summary>
/// SchmittAssignment4 Coin Game
/// ITDEV-185-900
/// </summary>

class Coin {
private:
    std::string sideUp;
    bool heads;
    double value;

public:
    Coin(double coinValue) {
        value = coinValue;
        toss(); // Randomly decide the initial side up
    }

    void toss() {
        // Randomly decide the side of the coin that is facing up
        if (rand() % 2 == 0) {
            sideUp = "HEADS";
            heads = true;
        }
        else {
            sideUp = "tails";
            heads = false;
        }
    }

    bool getHeads() {
        return heads;
    }

    double getValue() {
        return value;
    }

    std::string getSideUp() {
        return sideUp;
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    Coin quarter(0.25);
    Coin dime(0.10);
    Coin nickel(0.05);

    double balance = 0.0;

    while (balance < 1.0) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        std::cout << "Quarter: " << quarter.getSideUp() << std::endl;
        std::cout << "Dime: " << dime.getSideUp() << std::endl;
        std::cout << "Nickel: " << nickel.getSideUp() << std::endl;

        if (quarter.getHeads()) {
            balance += quarter.getValue();
            std::cout << "Quarter landed heads-up. Added 25 cents to your balance." << std::endl;
        }
        else
        {
            std::cout << "Quarter landed tails. Your balance remains the same." << std::endl;
        }

        if (dime.getHeads()) {
            balance += dime.getValue();
            std::cout << "Dime landed heads-up. Added 10 cents to your balance." << std::endl;
        }
        else
        {
            std::cout << "Dime landed tails. Your balance remains the same." << std::endl;
        }

        if (nickel.getHeads()) {
            balance += nickel.getValue();
            std::cout << "Nickel landed heads-up. Added 5 cents to your balance." << std::endl;
        }
        else
        {
            std::cout << "Nickel landed tails. Your balance remains the same." << std::endl;
        }

        std::cout << "Current balance: $" << balance << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }

    if (balance == 1.0) {
        std::cout << "Congratulations! You won the game!" << std::endl;
    }
    else {
        std::cout.precision(2);
        std::printf("Sorry, you lost the game. Your balance of $%.02f exceeded $1.", balance);
    }

    return 0;
}
