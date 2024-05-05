#pragma once
#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <string>
#include "json.hpp"

class Item {
public:
    int stockCount;
    double itemPrice;
    double itemDiscountPrice;

    Item();
    Item(int stockCount, double itemPrice, double itemDiscountPrice);

    void fromJson(const std::string& jsonString);
    std::string toJson() const;

    void print() const;
};

#endif // JSONOBJECT_H
