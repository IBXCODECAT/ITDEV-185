#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef SHOPPINGMANAGER_H
#define SHOPPINGMANAGER_H

// Include statements
#include <iostream>

// Include local headers
#include "Cart.hpp"
#include "ItemsManager.hpp"

/// <summary>
/// Wrapper class to manage the user's shopping cart
/// </summary>
static class ShoppingManager {
public:
    /// <summary>
	/// Add items to the cart
    /// </summary>
    static void addItems();

    /// <summary>
	/// Remove items from the cart
    /// </summary>
    static void removeItems();

    /// <summary>
	/// List all items in the cart
    /// </summary>
    static void listItems();

    /// <summary>
	/// Finish the shopping session and start the payment process
    /// </summary>
    static void finishAndPay();
};

#endif // SHOPPINGMANAGER_H