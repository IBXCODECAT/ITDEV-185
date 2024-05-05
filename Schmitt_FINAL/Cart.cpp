#include <string>
#include <vector>

#include "Cart.hpp"
#include "Item.hpp"
#include "ItemsManager.hpp"

static std::vector<Item> cart; // List of items in the cart

void Cart::addItem(Item& item, int itemCount)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (item.stockCount > 0)
        {
            cart.push_back(item);

            // Decrease the stock count of the item as it is added to the cart
            item.stockCount--;
        }
        else
        {
			std::cout << "Item out of stock: " << item.itemName << std::endl;
        }
    }

    std::cout << "Item added to the cart: " << item.itemName << " (Count: " << itemCount << ")" << std::endl;
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

    std::cout << "Receipt:" << std::endl;
    std::cout << std::setw(20) << std::left << "Item" << std::setw(10) << std::left << "Quantity" << std::setw(10) << std::left << "Price" << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    double total = 0.0;
    for (const auto& item : cart) {
        std::cout << std::setw(20) << std::left << item.itemName << std::setw(10) << std::left << 1 << "$" << std::fixed << std::setprecision(2) << item.itemPrice << std::endl;
        total += item.itemPrice;
    }

    std::cout << std::string(40, '-') << std::endl;
    std::cout << std::setw(30) << std::left << "Total:" << "$" << std::fixed << std::setprecision(2) << total << std::endl;
}
