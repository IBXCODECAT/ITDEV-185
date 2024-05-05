#pragma once
#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>  // Include the string header
#include "Item.hpp"

class ItemParser {
public:
    static Item readFromFile(const std::string itemName);  // Specify std::string
    static void writeToFile(const Item& obj);

private:
    static void ensureItemsDirectoryExists();
    static bool directoryExists(const std::string& directory);  // Specify std::string
};

#endif // JSONPARSER_H
