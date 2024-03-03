#ifndef COIN_H
#define COIN_H

#include <string>

class Coin {
private:
    static double balance;
    std::string sideUp;
    bool heads;
    double value;

public:
    Coin(double val);

    void toss();
    void addBalance();
    static double getBalance();
    bool getHeads();
    double getValue();
    std::string getSideUp();
};

#endif
