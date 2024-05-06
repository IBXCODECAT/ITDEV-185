// Include headers
#include <string>
#include <iostream>

// Include local headers
#include "ProductManager.hpp"
#include "Item.hpp"
#include "ItemsManager.hpp"

// Use the standard namespace
using namespace std;

void ProductManager::listProducts() {

	int productCount = ItemsManager::items.size();

	if (productCount == 0) {
		cout << "No products found. Why don't you create some in the store mode menu?\n";
		return;
	}

	for (const Item& item : ItemsManager::items) {
		cout << "\nNext Product...\n";
		item.print();
	}
}

void ProductManager::addProduct() {
	Item item;
	string itemName;
	string itemCategory;
	int stockCount;
	double itemPrice;
	double itemDiscountPrice;

	cout << "Enter the name of the product (No two products can have the same name):";
	cin >> itemName;
	cout << "Enter the category of the product (this will be used when discounting): ";
	cin >> itemCategory;
	cout << "Enter the stock count (The number of items in stock): ";
	cin >> stockCount;
	cout << "Enter the price of the product (You can manage discounts in another menu): ";
	cin >> itemPrice;

	strcpy_s(item.itemName, itemName.c_str());
	strcpy_s(item.itemCategory, itemCategory.c_str());
	item.stockCount = stockCount;
	item.itemPrice = itemPrice;
	item.itemDiscountPrice = itemPrice;

	ItemsManager::addItem(item);
}

void ProductManager::updateProduct() {
	Item item;
	string itemName;
	string itemCategory;
	int stockCount;
	double itemPrice;
	double itemDiscountPrice;

	cout << "Enter the name of the product to update: ";
	cin >> itemName;
	cout << "Enter the new category for this product (this will be used when discounting): ";
	cin >> itemCategory;
	cout << "Update the stock count (The number of items in stock): ";
	cin >> stockCount;
	cout << "Update the price of the product (You can manage discounts in another menu): ";
	cin >> itemPrice;

	ItemsManager::removeItem(itemName);

	strcpy_s(item.itemName, itemName.c_str());
	strcpy_s(item.itemCategory, itemCategory.c_str());
	item.stockCount = stockCount;
	item.itemPrice = itemPrice;
	item.itemDiscountPrice = itemPrice;

	ItemsManager::addItem(item);
}

void ProductManager::removeProduct() {
	string itemName;
	cout << "Enter the name of the product to remove: ";
	cin >> itemName;

	ItemsManager::removeItem(itemName);
}

void ProductManager::saveProducts() {
	ItemsManager::saveItemsToFile();
}

void ProductManager::discountCategory() {
	std::string category;
	double discount;

	// Get user input for category name
	std::cout << "Enter the category name to apply a discount to: ";
	std::cin >> category;

	// Check if the entered category exists
	bool categoryExists = false;
	for (const Item& item : ItemsManager::items) {
		if (item.itemCategory == category) {
			categoryExists = true;
			break;
		}
	}

	if (!categoryExists) {
		std::cout << "The category " << category << " does not exist!" << std::endl;
		return;
	}

	// Get user input for discount amount
	std::cout << "Enter the discount amount: ";
	std::cin >> discount;

	// Check if the discount input is a valid double with maximum two decimal places
	if (std::cin.fail() || discount < 0 || discount != std::floor(discount * 100) / 100) {
		std::cout << "Invalid discount amount! Please enter a non-negative double with maximum two decimal places." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	// Iterate over all items and apply discount to items in the specified category
	for (Item& item : ItemsManager::items) {
		if (item.itemCategory == category) {
			item.itemDiscountPrice = item.itemPrice - discount;
		}
	}
}

void ProductManager::discountCategoryByPercentage() {
	std::string category;
	double percentage;

	// Get user input for category name
	std::cout << "Enter the category name to discount: ";
	std::cin >> category;

	// Check if the entered category exists
	bool categoryExists = false;
	for (const Item& item : ItemsManager::items) {
		if (item.itemCategory == category) {
			categoryExists = true;
			break;
		}
	}

	if (!categoryExists) {
		std::cout << "The category " << category << "does not exist!" << std::endl;
		return;
	}

	// Get user input for discount percentage
	std::cout << "Enter the discount percentage: ";
	std::cin >> percentage;

	// Check if the percentage input is a valid double with maximum two decimal places
	if (std::cin.fail() || percentage < 0 || percentage > 100 || percentage != std::floor(percentage * 100) / 100) {
		std::cout << "Invalid discount percentage! Please enter a non-negative double between 0 and 100 with maximum two decimal places." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}

	// Iterate over all items and apply discount to items in the specified category
	for (Item& item : ItemsManager::items) {
		if (item.itemCategory == category) {
			// Calculate the discount amount based on the percentage of the item's price
			double discountAmount = item.itemPrice * (percentage / 100.0);
			// Apply the discount to the item's category discount
			item.itemDiscountPrice = item.itemPrice - discountAmount;
		}
	}
}