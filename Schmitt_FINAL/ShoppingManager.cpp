#include "ShoppingManager.hpp"

void ShoppingManager::addItems()
{
    std::string itemName;
    int itemCount;

    // Prompt user for item name and count
    std::cout << "Enter item name: ";
    std::cin >> itemName;
    std::cout << "Enter item count: ";
    std::cin >> itemCount;

    // Find the item from the items list
    Item* item = ItemsManager::findItem(itemName);
    if (item != nullptr) {
        Cart::addItem(*item, itemCount);
        std::cout << "Added " << itemCount << " " << itemName << "(s) to the cart." << std::endl;
    }
    else {
        std::cout << "Item not found! Try checking the list of availible items or adding an item yourself in STORE MODE!" << std::endl;
    }
}

void ShoppingManager::removeItems() {
    std::string itemName;
    int itemCount;

    // Prompt user for item name and count
    std::cout << "Enter item name: ";
    std::cin >> itemName;
    std::cout << "Enter item count: ";
    std::cin >> itemCount;

    // Remove items from the cart
    Cart::removeItem(itemName, itemCount);
}

void ShoppingManager::listItems()
{
    Cart::displayCart();
}

void ShoppingManager::finishAndPay()
{
	Cart::printReceipt();
}