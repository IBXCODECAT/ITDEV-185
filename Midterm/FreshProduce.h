#pragma once

#ifndef FRESHPRODUCE_H
#define FRESHPRODUCE_H

#include "Item.h"

class FreshProduce : public Item {
private:
    double pounds;

public:
    FreshProduce(std::string itemName, double itemPrice, double itemPounds);

    double calculatePrice() override;

    void setPounds(double itemPounds);

    double getPounds() const;
};

#endif // FRESHPRODUCE_H
