// Include headers
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>


// Include local headers
#include "Cart.hpp"
#include "Item.hpp"
#include "ItemsManager.hpp"

/// <summary>
/// List of items in the cart
/// </summary>
static std::vector<Item> cart;

/// <summary>
/// Debug flag to enable/disable debug messages
/// </summary>
constexpr bool DEBUG_FLAG = false;

void Cart::Clear()
{
    cart.clear();
}

unsigned int Cart::addItems(Item& item, int itemCount)
{
	unsigned int itemsAdded = 0;

    for (int i = 0; i < itemCount; i++)
    {
        if (item.stockCount > 0)
        {
            cart.push_back(item);

            // Decrease the stock count of the item as it is added to the cart
            item.stockCount--;
			itemsAdded++;
        }
        else
        {
			if (DEBUG_FLAG) std::cout << "Item out of stock: " << item.itemName << std::endl;
        }
    }

    std::cout << "Item added to the cart: " << item.itemName << " (Count: " << itemsAdded << ")" << std::endl;
    return itemsAdded;
}

void Cart::removeItem(std::string& itemName, int itemCount) {
    int removedCount = 0;
    auto it = cart.begin();
    while (it != cart.end() && removedCount < itemCount) {
        if (it->itemName == itemName) {
            it = cart.erase(it); // Erase the item from the cart
            removedCount++;

            // Increase the stock count of the item as it is removed from the cart
            it->stockCount++;
        }
        else {
            ++it;
        }
    }
    std::cout << "Removed " << removedCount << " " << itemName << "(s) from the cart." << std::endl;
}



void Cart::displayCart() {
    if (cart.empty()) {
        std::cout << "Cart is empty." << std::endl;
    }
    else {
        std::cout << "Items in the cart:" << std::endl;
        for (const auto& item : cart) {
            std::cout << "- " << item.itemName << " (Price: $" << std::fixed << std::setprecision(2) << item.itemPrice << ") ";
            if (item.itemDiscountPrice < item.itemPrice) {
                std::cout << "{Discounted Price: $" << std::fixed << std::setprecision(2) << item.itemDiscountPrice << "} ";
            }
            std::cout << std::endl;
        }
    }
}

void Cart::printReceipt() {
    if (cart.empty()) {
        std::cout << "Cart is empty. No receipt to print." << std::endl;
        return;
    }

    // Map to store item names and their quantities
    std::unordered_map<std::string, int> itemQuantityMap;
    for (const auto& item : cart) {
        itemQuantityMap[item.itemName]++;
    }

    std::cout << "Receipt:" << std::endl;
    std::cout << std::setw(20) << std::left << "Item" << std::setw(10) << std::left << "Quantity" << std::setw(10) << std::left << "Price" << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    double subtotal = 0.0;
    for (auto it = itemQuantityMap.begin(); it != itemQuantityMap.end(); ++it) {
        const std::string& itemName = it->first;
        int quantity = it->second;
        for (const auto& item : cart) {
            if (item.itemName == itemName) {
                std::cout << std::setw(20) << std::left << itemName << std::setw(10) << std::left << quantity << "$" << std::fixed << std::setprecision(2) << item.itemDiscountPrice << std::endl;
                subtotal += item.itemPrice * quantity;
                break;
            }
        }
    }

    // Calculate sales tax (assuming 8%)
    double salesTax = subtotal * 0.08;
    // Calculate tip (20%)
    double tip = subtotal * 0.20;

    // Add sales tax and tip to subtotal to get total
    double total = subtotal + salesTax + tip;

    std::cout << std::string(40, '-') << std::endl;
    std::cout << std::setw(30) << std::left << "Subtotal:" << "$" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    std::cout << std::setw(30) << std::left << "Sales Tax (8%):" << "$" << std::fixed << std::setprecision(2) << salesTax << std::endl;
    std::cout << std::setw(30) << std::left << "Tip (20%):" << "$" << std::fixed << std::setprecision(2) << tip << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    std::cout << std::setw(30) << std::left << "Total:" << "$" << std::fixed << std::setprecision(2) << total << std::endl;
}