#include <iostream>
#include <fstream>
#include <string>

// Include the nlohmann JSON headers
#include "json.hpp"
#include "Item.hpp"
#include "ItemParser.hpp"
#include "ItemsManager.hpp"

#include "./UI/Menu.hpp";

using namespace std;
using json = nlohmann::json;

int main() {
    
    Menu menu;

    bool exitSystem = false;
    
    menu.addChild("Shopping Mode");
    menu.addChild("Store Mode");

    menu.navigate(1); // Navigate to the first child

    menu.addChild("Add item(s) to Cart");
    menu.addChild("Remove item(s) from Cart");
    menu.addChild("List all availible products");
    menu.addChild("Finish & Pay");

    menu.navigate(1); // Navigate to the first child
    menu.addChild("Scan by Id");
    menu.addChild("Scan by Name");

    menu.goBack();

    menu.goBack(); // Go back to the parent menu
    menu.navigate(2); // Navigate to the second child

    menu.addChild("Create a product.");
    menu.addChild("Update product metadata (eg. Price, Discounts, etc)");
    menu.addChild("Delete a product");
    menu.addChild("Save my changes");

    menu.goBack();

    int choice;

    while (!exitSystem)
    {
        menu.display();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        menu.navigate(choice);
    }

    /*

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

    */

    return 0;
}
