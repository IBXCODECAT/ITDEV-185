#include "ItemsManager.hpp"
#include <iostream>

std::vector<Item> ItemsManager::items;

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

std::vector<Item> ItemsManager::getAllItems() {
    // Retrieve all items from the global items vector
    return items;
}

void ItemsManager::saveItemsToFile() {
    

    // Clear the items directory
    ItemParser::purgeItemsDirectory();

    std::cout << "Saving items to files..." << std::endl;

    // Save the current vector of items to files
    for (const Item& item : items) {
        ItemParser::writeToFile(item);
        std::cout << "Saved item: " << item.itemName << std::endl;
    }
}

void ItemsManager::deleteAllItems() {
	// Delete all items from the global items vector

	items.clear();
    ItemParser::purgeItemsDirectory(); // Clear the items directory
}