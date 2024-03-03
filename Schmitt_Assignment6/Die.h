#ifndef DIE_H
#define DIE_H

///<summary>
/// Class representing a single die.
///</summary>
class Die {
private:
    int value;

public:
    ///<summary>
    /// Constructor for Die class.
    ///</summary>
    Die();

    ///<summary>
    /// Rolls the die, generating a random value between 1 and 6.
    ///</summary>
    void roll();

    ///<summary>
    /// Gets the value of the last roll.
    ///</summary>
    ///<returns>The value of the last roll.</returns>
    int getValue();
};

#endif // DIE_H
