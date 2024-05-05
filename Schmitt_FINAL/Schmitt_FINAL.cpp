#include <iostream>
#include <fstream>
#include <string>

// Include the nlohmann JSON headers
#include "json.hpp"
#include "Item.hpp"
#include "ItemParser.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    Item obj;
    
    strcpy_s(obj.itemName, "Apples");
    obj.itemPrice = 12.94;
    obj.itemDiscountPrice = 9.99;
    obj.stockCount = 100;

    // Write JSON to file
    ItemParser::writeToFile(obj);

    strcpy_s(obj.itemName, "Bananas");
    obj.itemPrice = 2.24;
    obj.itemDiscountPrice = 1.41;
    obj.stockCount = 12;

    ItemParser::writeToFile(obj);

    // Read JSON from file
    Item newObj;
    newObj = ItemParser::readFromFile("Apples");

    // Print the read object
    newObj.print();

    newObj = ItemParser::readFromFile("Bananas");
    newObj.print();

    return 0;
}
