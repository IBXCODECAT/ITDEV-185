#ifndef REEL_H
#define REEL_H

#include <string>

class Reel {
private:
    std::string faces[20] = { "lemon     ", "cherry    ", "banana    ", "seven     ", "diamond  ", "bell      ", "heart     ", "star      ", "strawberry", "grape     ", "bell      ", "horseshoe", "heart     ", "pear      ", "orange     ", "10        ", "king      "      , "queen     ", "jack      ", "joker     " };
    std::string currentFace;
public:
    Reel();
    void spin();
    std::string getFace() const;
};

#endif
