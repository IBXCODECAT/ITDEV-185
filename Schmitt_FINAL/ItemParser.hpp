#pragma once
#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include "Item.hpp"

class ItemParser {
public:
    static void readFromFile(const std::string& filename, Item& obj);
    static void writeToFile(const std::string& filename, const Item& obj);
};

#endif // JSONPARSER_H
