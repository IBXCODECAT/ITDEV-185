#include "ItemsManager.hpp"
#include <iostream>

constexpr bool DEBUG_FLAG = false;

std::vector<Item> ItemsManager::items; // List of all items in the store

void ItemsManager::initialize() {
    // Get all items from the item parser and initialize the global items vector
    items = ItemParser::readAllItems();
}

Item* ItemsManager::findItem(const std::string& itemName) {
    // Find and return the item with the specified name
    for (auto& item : ItemsManager::items) {
        if (item.itemName == itemName) {
            return &item;
        }
    }
    return nullptr; // Item not found
}

void ItemsManager::addItem(const Item& item) {

    // Add an item to the global items vector
    items.push_back(item);
}

void ItemsManager::removeItem(const std::string& itemName) {
    // Remove an item from the global items vector
    items.erase(std::remove_if(items.begin(), items.end(), [&](const Item& item) {
        return item.itemName == itemName;
        }), items.end());
}

void ItemsManager::saveItemsToFile() {
    

    // Clear the items directory
    ItemParser::purgeItemsDirectory();

    std::cout << "Saving changes to store inventory..." << std::endl;

    // Save the current vector of items to files
    for (const Item& item : items) {
        ItemParser::writeToFile(item);
        if (DEBUG_FLAG) std::cout << "Saved item: " << item.itemName << std::endl;
    }
}

void ItemsManager::deleteAllItems() {
	// Delete all items from the global items vector

	items.clear();
    ItemParser::purgeItemsDirectory(); // Clear the items directory
}