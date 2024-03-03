#include <iostream>
#include <ctime>
#include "Player.h"

using namespace std;

///<summary>
/// Initializes the players array by setting player numbers and rolling dice for each player.
///</summary>
///<param name="players">Array of Player objects to initialize.</param>
void initPlayers(Player players[]) {
    for (int i = 1; i <= 100; ++i) { // Start from 1 instead of 0
        players[i - 1].setPlayerNumber(i); // Adjust index to start from 0
        players[i - 1].play();
    }
}

///<summary>
/// Finds the player with the highest total sum of dice rolls.
///</summary>
///<param name="players">Array of Player objects to search.</param>
///<returns>Pointer to the player with the highest total sum of dice rolls.</returns>
Player* findWinner(Player players[]) {
    Player* winner = &players[0];
    for (int i = 1; i < 100; ++i) {
        if (players[i].getSumOfDice() > winner->getSumOfDice()) {
            winner = &players[i];
        }
    }
    return winner;
}

///<summary>
/// Displays the player with the highest total sum of dice rolls.
///</summary>
///<param name="winner">Pointer to the winning player.</param>
void displayWinner(Player* winner) {
    cout << "Player " << winner->getPlayerNumber() << " had the highest total of combined dice rolled." << endl;
    cout << "Player " << winner->getPlayerNumber() << "'s total sum: " << winner->getSumOfDice() << endl;
}

///<summary>
/// Displays the sum of dice rolls for each player.
///</summary>
///<param name="players">Array of Player objects to display.</param>
void displayAllPlayersSums(Player players[]) {
    cout << "Displaying sum of dice rolls for each player:" << endl;
    for (int i = 1; i <= 100; ++i) { // Start from 1 instead of 0
        cout << "Player " << i << "'s total sum: " << players[i - 1].getSumOfDice() << endl; // Adjust index to start from 0
        if (i % 5 == 0) {
            cout << endl; // Separate every 5 players for readability
        }
    }
}

int main() {

    // UNCOMMENT THIS LINE FOR TRUE RANDOM NUMBERS
    srand(time(0)); // Seed the random number generator with seed zero

    Player players[100];
    initPlayers(players);

    displayAllPlayersSums(players);

    Player* winner = findWinner(players);
    displayWinner(winner);

    return 0;
}
