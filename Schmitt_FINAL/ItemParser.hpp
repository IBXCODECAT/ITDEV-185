#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef JSONPARSER_H
#define JSONPARSER_H

// Include statements
#include <string>

// Include local headers
#include "Item.hpp"

/// <summary>
/// Utility class to read and write items to and from files
/// </summary>
static class ItemParser {
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
    /// <summary>
	/// Ensure that the items directory exists to prevent file I/O errors
    /// </summary>
    static void ensureItemsDirectoryExists();

    /// <summary>
	/// Verify if a directory exists to prevent file I/O errors
    /// </summary>
    /// <param name="directory">The directory to check</param>
    /// <returns>True if the directory exists</returns>
    static bool directoryExists(const std::string& directory);  // Specify std::string
};

#endif // JSONPARSER_H
