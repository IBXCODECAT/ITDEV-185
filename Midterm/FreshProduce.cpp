#include "FreshProduce.h"

FreshProduce::FreshProduce(std::string itemName, double itemPrice, double itemPounds)
    : Item(itemName, itemPrice), pounds(itemPounds) {}

double FreshProduce::calculatePrice() {
    return price * pounds;
}

void FreshProduce::setPounds(double itemPounds) {
    pounds = itemPounds;
}

double FreshProduce::getPounds() const {
    return pounds;
}
