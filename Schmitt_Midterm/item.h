#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    double price;

public:
    static double delivery;
    static double tip;

    Item(std::string itemName, double itemPrice);

    virtual double calculatePrice() = 0;

    std::string getName() const;

    double getPrice() const;
};

#endif // ITEM_H
