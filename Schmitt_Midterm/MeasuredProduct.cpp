#include "MeasuredProduct.h"

MeasuredProduct::MeasuredProduct(std::string itemName, double itemPrice, int itemQuantity)
    : Item(itemName, itemPrice), quantity(itemQuantity) {}

double MeasuredProduct::calculatePrice() {
    return price * quantity;
}

void MeasuredProduct::setQuantity(int itemQuantity) {
    quantity = itemQuantity;
}

int MeasuredProduct::getQuantity() const {
    return quantity;
}
