#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef CART_H
#define CART_H

// Include statements
#include <iostream>
#include <vector>
#include <algorithm>

// Include local headers
#include "Item.hpp"

/// <summary>
/// Class to represent the shopping cart of the user
/// </summary>
static class Cart {
public:
    /// <summary>
	/// Clear the cart of all items
    /// </summary>
    static void Clear();

    /// <summary>
	/// Add items to the cart and decreases the stock count of the item
    /// </summary>
    /// <param name="item">The item to add to the cart</param>
    /// <param name="itemCount">The number of these items we are requesting to add to the cart</param>
    /// <returns>The number of items actually added to the cart</returns>
    static unsigned int addItems(Item& item, const int itemCountRequested);

    /// <summary>
	/// Removes items from the cart and increases the stock count of the item
    /// </summary>
    /// <param name="itemName">The name of the item(s) to remove</param>
    /// <param name="itemCount">The number of items to remove</param>
    static void removeItem(std::string& itemName, int itemCount);

    /// <summary>
	/// Display the contents of the cart
    /// </summary>
    static void displayCart();

    /// <summary>
	/// Neatly print the receipt of the cart to the console
    /// </summary>
    static void printReceipt();
};

#endif // CART_H