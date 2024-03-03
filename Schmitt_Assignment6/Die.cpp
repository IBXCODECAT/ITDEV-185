#include "Die.h"
#include <cstdlib>

Die::Die() {
    roll();
}

void Die::roll() {
    value = rand() % 6 + 1;
}

int Die::getValue() {
    return value;
}
