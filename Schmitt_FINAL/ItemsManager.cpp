#include "ItemsManager.hpp"

std::vector<Item> ItemsManager::items;

void ItemsManager::initialize() {
    // Get all items from the item parser and initialize the global items vector
    items = ItemParser::readAllItems();
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

void ItemsManager::updateItem(const Item& item) {
    // Update an item in the global items vector
    for (Item& currentItem : items) {
        if (currentItem.itemName == item.itemName) {
            currentItem = item;
            return;
        }
    }
}

std::vector<Item> ItemsManager::getAllItems() {
    // Retrieve all items from the global items vector
    return items;
}

void ItemsManager::saveItemsToFile() {
    
    // Clear the items directory
    ItemParser::purgeItemsDirectory();

    // Save the current vector of items to files
    for (const Item& item : items) {
        ItemParser::writeToFile(item);
    }
}

void ItemsManager::deleteAllItems() {
	// Delete all items from the global items vector

	items.clear();
    ItemParser::purgeItemsDirectory(); // Clear the items directory
}