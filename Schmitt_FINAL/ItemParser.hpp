#pragma once
#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>  // Include the string header
#include "Item.hpp"

class ItemParser {
public:

    /// <summary>
    /// Read an item from a file in the items directory
    /// </summary>
    /// <param name="itemName">The name of the item to deserialize</param>
    /// <returns>The resulting item</returns>
    static Item readFromFile(const std::string itemName);  // Specify std::string
    
    /// <summary>
    /// Write an item to a file in the items directory
    /// </summary>
    /// <param name="obj">The Item to serialize</param>
    static void writeToFile(const Item& obj);
    
    /// <summary>
    /// Read all items from the items directory
    /// </summary>
    /// <returns>A vector of items</returns>
    static std::vector<Item> readAllItems();

    /// <summary>
    /// Delete everything in the items directory
    /// </summary>
    static void purgeItemsDirectory();

private:
    static void ensureItemsDirectoryExists();
    static bool directoryExists(const std::string& directory);  // Specify std::string
};

#endif // JSONPARSER_H
