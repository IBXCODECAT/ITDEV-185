// Include local headers
#include "ShoppingManager.hpp"
#include "ProductManager.hpp"

// Use the standard namespace
using namespace std;

void ShoppingManager::addItems()
{
    std::string itemName;
    int requestedItemCount;

    // Prompt user for item name and count
    std::cout << "Enter item name: ";
    std::cin >> itemName;
    std::cout << "Enter item count: ";
    std::cin >> requestedItemCount;

    // Find the item from the items list
    Item* item = ItemsManager::findItem(itemName);
    if (item != nullptr) {
        unsigned int actualItemCount = Cart::addItems(*item, requestedItemCount);
        std::cout << "Added " << actualItemCount << " " << itemName << "(s) to the cart." << std::endl;

		if (actualItemCount < requestedItemCount) {
			int itemCountDifference = requestedItemCount - actualItemCount;

			std::cout << itemName << " is now out of stock! You currently have " << itemCountDifference << " less of them in your cart than initially requested!" << std::endl;
		}
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
	// Print the receipt
	Cart::printReceipt();

	// Save the products
	ProductManager::saveProducts();

	// Clear the cart
	Cart::Clear();

	// Output a thank you message
    cout << "\n\nThank you for shopping with us! Have a great day!\n\n";
}