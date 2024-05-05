#include <iostream>
#include <fstream>
#include <string>

// Include the nlohmann JSON headers
#include "json.hpp"
#include "Item.hpp"
#include "ItemParser.hpp"
#include "ItemsManager.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    Item obj;
    
    strcpy_s(obj.itemName, "Walking Stick");
    obj.itemPrice = 12.94;
    obj.itemDiscountPrice = 9.99;
    obj.stockCount = 100;

    Item obj2;

    strcpy_s(obj2.itemName, "Egg");
    obj2.itemPrice = 2.24;
    obj2.itemDiscountPrice = 1.41;
    obj2.stockCount = 12;

    
    ItemsManager::initialize();
    ItemsManager::deleteAllItems();

    ItemsManager::addItem(obj);
    ItemsManager::addItem(obj2);

    ItemsManager::saveItemsToFile();

    cout << "Reading all items..." << endl;

    std::vector<Item> items = ItemParser::readAllItems();

    for (const Item& item : items) {
		item.print();
	}


    return 0;
}
