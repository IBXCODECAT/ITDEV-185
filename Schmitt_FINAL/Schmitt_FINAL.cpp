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
    obj.itemPrice = 12.94;
    obj.itemDiscountPrice = 9.99;
    obj.stockCount = 100;

    // Write JSON to file
    ItemParser::writeToFile("data.json", obj);

    // Read JSON from file
    Item newObj;
    ItemParser::readFromFile("data.json", newObj);

    // Print the read object
    newObj.print();

    return 0;
}
