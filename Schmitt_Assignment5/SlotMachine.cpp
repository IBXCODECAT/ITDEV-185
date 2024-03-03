#include "SlotMachine.h"
#include <iostream>

SlotMachine::SlotMachine() {
    playCount = 0;
}

void SlotMachine::play() {
    for (int i = 0; i < 3; ++i) {
        reels[i].spin();

        std::cout << reels[i].getFace() << "\t\t";

        if (i == 2)
        {
            std::cout << std::endl;
        }
    }
    ++playCount;
}

bool SlotMachine::isWinner() const {
    
    //Return false if data is null
    if (reels[0].getFace() == "")
    {
        return false;
    }
    
    return (reels[0].getFace() == reels[1].getFace()) && (reels[1].getFace() == reels[2].getFace());

}

int SlotMachine::getPlayCount() const {
    return playCount;
}
