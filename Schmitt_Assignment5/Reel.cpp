#include "Reel.h"
#include <cstdlib>
#include <ctime>

Reel::Reel() {
    // Seed the random number generator
    srand(time(NULL));
}

void Reel::spin() {
    int randomIndex = rand() % 20;
    currentFace = faces[randomIndex];
}

std::string Reel::getFace() const {
    return currentFace;
}
