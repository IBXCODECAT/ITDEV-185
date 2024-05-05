#pragma once

#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Item.hpp"

static class Cart {
public:
    // Method to add an item to the cart
    static void addItem(Item& item, const int itemCount);

    // Method to remove an item from the cart
    static void removeItem(std::string& itemName, int itemCount);

    // Method to display the items in the cart
    static void displayCart();

    static void printReceipt();
};

#endif // CART_H