#include "SlotMachine.h"
#include <iostream>

// Author: Nathan Schmitt
// Class: ITDEV-185

int main() {
    SlotMachine slotMachine;
    while (!slotMachine.isWinner()) {
        slotMachine.play();
    }
    std::cout << "Congratulations! You won after " << slotMachine.getPlayCount() << " plays." << std::endl;
    return 0;
}
