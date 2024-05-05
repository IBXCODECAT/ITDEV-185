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
        }
        else {
            ++it;
        }
    }
    std::cout << "Removed " << removedCount << " " << itemName << "(s) from the cart." << std::endl;
}



void Cart::displayCart()
{
    if (cart.empty())
    {
        std::cout << "Cart is empty." << std::endl;
    }
    else
    {
        std::cout << "Items in the cart:" << std::endl;
        for (const auto& item : cart)
        {
            std::cout << "- " << item.itemName << " (Count: " << item.stockCount << ")" << std::endl;
        }
    }
}

