#pragma once

#ifndef MEASUREDPRODUCT_H
#define MEASUREDPRODUCT_H

#include "Item.h"

class MeasuredProduct : public Item {
private:
    int quantity;

public:
    MeasuredProduct(std::string itemName, double itemPrice, int itemQuantity);

    double calculatePrice() override;

    void setQuantity(int itemQuantity);

    int getQuantity() const;
};

#endif // MEASUREDPRODUCT_H
