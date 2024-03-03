#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include "Reel.h"

class SlotMachine {
private:
    Reel reels[3];
    int playCount;
public:
    SlotMachine();
    void play();
    bool isWinner() const;
    int getPlayCount() const;
};

#endif
