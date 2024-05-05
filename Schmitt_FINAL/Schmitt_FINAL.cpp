// Include C++_lang standard headers
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

// Include local headers
#include "json.hpp"
#include "Item.hpp"
#include "ItemParser.hpp"
#include "ItemsManager.hpp"
#include "ProductManager.hpp"
#include "./UI/Menu.hpp";

// Define constants
constexpr bool DEBUG_FLAG = false;
constexpr short THREAD_SLEEP_TIME_MS = 100;

// Use the standard namespace
using namespace std;
// Use the nlohmann json namespace
using json = nlohmann::json;

// Define global variables
static Menu menu;
static bool MenuProgressionEnabled = true;

/// <summary>
/// Function to display a message and wait for user input
/// Primarily used for debugging purposes, to pause the console output
/// </summary>
static void waitForInput() {
    std::cout << "Enter [0] to Continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get(); // Wait for user to press any key
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    
    // If the DEBUG_FLAG is set to false, allow the user to continue
    if (!DEBUG_FLAG) MenuProgressionEnabled = true;
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::listProducts() function
/// </summary>
static void oCallbackWrapperListProducts()
{
	MenuProgressionEnabled = false;
	ProductManager::listProducts();
    waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::addProduct() function
/// </summary>
static void oCallbackWrapperCreateProduct()
{ 
    MenuProgressionEnabled = false;
    ProductManager::addProduct();
    waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::updateProduct() function
/// </summary>
static void oCallbackWrapperUpdateProduct()
{
    MenuProgressionEnabled = false;
    ProductManager::updateProduct();
    waitForInput();
}

/// <summary>
/// Syncrhonous callback wrapper for the ProductManager::removeProduct() function
/// </summary>
static void oCallbackWrapperDeleteProduct()
{
    MenuProgressionEnabled = true;
    ProductManager::removeProduct();
    waitForInput();
}

/// <summary>
/// Syncrhonous callback wrapper for the ProductManager::SaveProducts() function
/// </summary>
static void oCallbackSaveProducts()
{
    MenuProgressionEnabled = true;
    ProductManager::saveProducts();
    waitForInput();
}

/// <summary>
/// Responsible for constructing the menu structure and adding options to the menu
/// </summary>
static void ConstructMenu()
{
	menu.addChild("Shopping Mode");
	menu.addChild("Store Mode");
    menu.addOption("Close Application", []() { exit(0); });

	menu.navigate(1); // Navigate to ADD ITEM(S) TO CART
    menu.addOption("Add item(s) to the cart.", waitForInput);
    menu.addOption("Remove item(s) from the cart.", waitForInput);
    menu.addOption("List all availible products.", waitForInput);
    menu.addOption("Finish & Pay.", waitForInput);

	menu.goBack(); // Navigate back to SHOPPING MODE
	menu.goBack(); // Navigate back to the root menu

	menu.navigate(2); // Navigate to STORE MODE

    menu.addOption("List all products.", oCallbackWrapperListProducts);
    menu.addOption("Create a product.", oCallbackWrapperCreateProduct);
    menu.addOption("Update product metadata (eg. Price, Discounts, etc)", oCallbackWrapperUpdateProduct);
    menu.addOption("Delete a product.", oCallbackWrapperDeleteProduct);
    menu.addOption("Save my changes.", oCallbackSaveProducts);

	menu.goBack();
}

/// <summary>
/// Entry point for the application - main function
/// </summary>
/// <returns>Windows Application Exit code</returns>
int main()
{
    // Initialize the menu structure
    ConstructMenu();

    // Initialize the items manager
    ItemsManager::initialize();

    int choice;

    // Main menu loop
    while (true)
    {
        // Display the menu and get the user's choice
        menu.display();
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        // Wait for the current operation to finish before proceeding if one exists...
        while (!MenuProgressionEnabled)
        {
            if (DEBUG_FLAG) std::cout << "Please wait for the current operation to finish..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(THREAD_SLEEP_TIME_MS));
        }

        // Process the user's choice
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
