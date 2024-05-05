#pragma once
#ifndef ITEMSMANAGER_H
#define ITEMSMANAGER_H

#include "Item.hpp"
#include "ItemParser.hpp"

#include <vector>

class ItemsManager {
public:

    /// <summary>
    /// Initialize the items manager by reading all saved items from the item parser
    /// </summary>
    static void initialize(); // Initialize the items manager

    /// <summary>
    /// Find an item in the global items vector by name
    /// </summary>
    /// <param name="itemName">The item namme to search for</param>
    /// <returns>The item if found</returns>
    static Item* findItem(const std::string& itemName);

    /// <summary>
    /// Add an item to the global items vector
    /// </summary>
    /// <param name="item">The item to add</param>
    static void addItem(const Item& item);

    /// <summary>
    /// Remove an item from the global items vector
    /// </summary>
    /// <param name="itemName">The item to remove</param>
    static void removeItem(const std::string& itemName);

    /// <summary>
    /// Get all items from the global items vector
    /// </summary>
    /// <returns>All saved items</returns>
    static std::vector<Item> getAllItems(); // Retrieve all items from the global items vector

    /// <summary>
    /// Saves the current vector of items to files using the item parser in the items directory
    /// </summary>
    static void saveItemsToFile();

    /// <summary>
    /// Delete all items from the global items vector
    /// </summary>
    static void deleteAllItems(); // Delete all items from the global items vector

private:
    static std::vector<Item> items; // Global items vector
};

#endif // ITEMSMANAGER_H
