#pragma once

// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef ITEM_H
#define ITEM_H

// Include statements
#include <string>

// Include local headers
#include "json.hpp"

/// <summary>
/// Class to represent an item in the store
/// </summary>
class Item {
public:
    char itemName[100]; // Assuming a maximum length of 100 characters for the item name
    int stockCount;
    double itemPrice;
    double itemDiscountPrice;

    /// <summary>
	/// Empty constructor
    /// </summary>
    Item();

    /// <summary>
	/// Constructor to initialize the item with the given values
    /// </summary>
    /// <param name="itemName">The name for this item</param>
    /// <param name="stockCount">The stock count for this item</param>
    /// <param name="itemPrice">The price for this item</param>
    /// <param name="itemDiscountPrice">The discounted price for this item</param>
    Item(const char* itemName, int stockCount, double itemPrice, double itemDiscountPrice);

    /// <summary>
	/// Parse the item from a JSON string representation and set the values
    /// </summary>
    /// <param name="jsonString">The json string to parse</param>
    void fromJson(const std::string& jsonString);

    /// <summary>
	/// Convert the item to a JSON string representation
    /// </summary>
    /// <returns>A JSON string representation</returns>
    std::string toJson() const;

    /// <summary>
	/// Print the item details to the console - used for simple displays and debugging
    /// </summary>
    void print() const;
};

#endif // JSONOBJECT_H
