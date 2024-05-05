#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "json.hpp"

class Item {
public:
    char itemName[100]; // Assuming a maximum length of 100 characters for the item name
    int stockCount;
    double itemPrice;
    double itemDiscountPrice;

    Item();
    Item(const char* itemName, int stockCount, double itemPrice, double itemDiscountPrice);

    void fromJson(const std::string& jsonString);
    std::string toJson() const;

    void print() const;

    bool operator==(const Item& other) const {
        return (this->itemName == other.itemName && this->stockCount == other.stockCount);
    }
};

#endif // JSONOBJECT_H
