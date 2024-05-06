// Include C++_lang standard headers
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

// Include local headers
#include "json.hpp"
#include "Item.hpp"
#include "ItemParser.hpp"
#include "ProductManager.hpp"
#include "ShoppingManager.hpp"
#include "./UI/Menu.hpp"

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
    
    // If the DEBUG_FLAG is not raised, allow the user to continue to navigate the menus
    if (!DEBUG_FLAG) MenuProgressionEnabled = true;
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::listProducts() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void listProductsWrapper()
{
    MenuProgressionEnabled = false;
    ProductManager::listProducts();
    waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ShoppingManager::listItems() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void cartDisplayWrapper()
{
	MenuProgressionEnabled = false;
	ShoppingManager::listItems();
	waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ShoppingManager::addItems() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void cartItemAddWrapper()
{
	MenuProgressionEnabled = false;
    ShoppingManager::addItems();
	waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ShoppingManager::removeItems() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void cartItemRemoveWrapper()
{
	MenuProgressionEnabled = false;
    ShoppingManager::removeItems();
	waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ShoppingManager::finishAndPay() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void finishAndPayWrapper()
{
	MenuProgressionEnabled = false;
    ShoppingManager::finishAndPay();
    waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::addProduct() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void createProductWrapper()
{ 
    MenuProgressionEnabled = false;
    ProductManager::addProduct();
    waitForInput();
}

/// <summary>
/// Synchronous callback wrapper for the ProductManager::updateProduct() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void updateProductWrapper()
{
    MenuProgressionEnabled = false;
    ProductManager::updateProduct();
    waitForInput();
}

/// <summary>
/// Syncrhonous callback wrapper for the ProductManager::removeProduct() function
/// This function is used to effectivley wrap the asynchronous function call in a synchronous one
/// </summary>
static void deleteProductWrapper()
{
    MenuProgressionEnabled = true;
    ProductManager::removeProduct();
    waitForInput();
}

/// <summary>
/// Syncrhonous callback wrapper for the ProductManager::SaveProducts() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void saveProductsWrapper()
{
    MenuProgressionEnabled = true;
    ProductManager::saveProducts();
    waitForInput();
}

/// <summary>
/// Syncrhonous callback wrapper for the ProductManager::discountCategory() function
/// This function is used to effectively wrap the asynchronous function call in a synchronous one
/// </summary>
static void discountCategoryWrapper()
{
	MenuProgressionEnabled = true;
	ProductManager::discountCategory();
	waitForInput();
}

/// <summary>
/// Responsible for constructing the menu structure and adding options to the menu
/// </summary>
static void ConstructMenu()
{
	// Add the main menu options
	menu.addChild("Shopping Mode");
	menu.addChild("Store Mode");
    menu.addOption("Close Application", []() { exit(0); });

	menu.navigate(1); // Navigate to ADD ITEM(S) TO CART

	// Add the shopping menu options
    menu.addOption("View cart.", cartDisplayWrapper);
    menu.addOption("Add item(s) to the cart.", cartItemAddWrapper);
    menu.addOption("Remove item(s) from the cart.", cartItemRemoveWrapper);
    menu.addOption("List all availible products.", listProductsWrapper);
    menu.addOption("Finish & Pay.", finishAndPayWrapper);
    
	menu.goBack(); // Navigate back to SHOPPING MODE
	menu.goBack(); // Navigate back to the root menu
	menu.navigate(2); // Navigate to STORE MODE

	// Add the store menu options
    menu.addChild("Manage Discounts");
	menu.addChild("Product Management");
    menu.addOption("List all products.", listProductsWrapper);

	menu.navigate(1); // Navigate to MANAGE DISCOUNTS

    // Add the discount menu options
    menu.addOption("Discount by category (fixed).", discountCategoryWrapper);
    menu.addOption("Discount by category (percentage).", discountCategoryWrapper);
	menu.addOption("Save my changes.", saveProductsWrapper);

	menu.goBack(); // Navigate back to STORE MODE
	menu.navigate(2); // Navigate to PRODUCT MANAGEMENT

	// Add the product management menu options
    menu.addOption("Create a product.", createProductWrapper);
    menu.addOption("Update product metadata (eg. price, etc).", updateProductWrapper);
    menu.addOption("Delete a product.", deleteProductWrapper);
    menu.addOption("Save my changes.", saveProductsWrapper);

	menu.goBack(); // Navigate back to STORE MODE
	menu.goBack(); // Navigate back to the root menu

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

    // Exit the application (Unreachable and useless code here to prevent compiler warnings)
    return 0;
}
