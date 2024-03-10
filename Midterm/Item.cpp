#include "Item.h"

double Item::delivery = 20.0;
double Item::tip = 5.0;

Item::Item(std::string itemName, double itemPrice) : name(itemName), price(itemPrice) {}

std::string Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;
}
