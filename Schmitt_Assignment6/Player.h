#ifndef PLAYER_H
#define PLAYER_H

#include "Die.h"

///<summary>
/// Class representing a player in the game.
///</summary>
class Player {
private:
    Die dice[20];
    int playerNumber;
    int sumOfDice;

public:
    ///<summary>
    /// Default constructor with optional params for Player class.
    ///</summary>
    Player(int number = 0);

    ///<summary>
    /// Rolls the dice for the player and calculates the sum of all rolls.
    ///</summary>
    void play();

    ///<summary>
    /// Gets the number of dice the player has.
    ///</summary>
    ///<returns>The number of dice.</returns>
    int getNumberOfDice();

    ///<summary>
    /// Gets the player number.
    ///</summary>
    ///<returns>The player number.</returns>
    int getPlayerNumber();

    ///<summary>
    /// Gets the value of a single die.
    ///</summary>
    ///<param name="index">The index of the die in the array.</param>
    ///<returns>The value of the die at the specified index.</returns>
    int getSingleDieValue(int index);

    ///<summary>
    /// Gets the sum of all dice rolls.
    ///</summary>
    ///<returns>The sum of all dice rolls.</returns>
    int getSumOfDice();

    ///<summary>
    /// Sets the player number.
    ///</summary>
    ///<param name="number">The player number to set.</param>
    void setPlayerNumber(int number);
};

#endif // PLAYER_H
