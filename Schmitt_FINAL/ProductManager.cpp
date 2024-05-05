#include "ProductManager.hpp"

#include "Item.hpp"
#include "ItemsManager.hpp"

#include <string>
#include <iostream>

using namespace std;

ProductManager::ProductManager() {}

void ProductManager::listProducts() {

	vector<Item> items = ItemsManager::getAllItems();

	int productCount = items.size();

	if (productCount == 0) {
		cout << "No products found. Why don't you create some?\n";
		return;
	}

	for (const Item& item : items) {
		cout << "\nNext Product...\n";
		item.print();
	}
}

void ProductManager::addProduct() {
	Item item;
	string itemName;
	int stockCount;
	double itemPrice;
	double itemDiscountPrice;

	cout << "Enter the name of the product: ";
	cin >> itemName;
	cout << "Enter the stock count: ";
	cin >> stockCount;
	cout << "Enter the price of the product: ";
	cin >> itemPrice;
	cout << "Enter the discounted price of the product: ";
	cin >> itemDiscountPrice;

	strcpy_s(item.itemName, itemName.c_str());
	item.stockCount = stockCount;
	item.itemPrice = itemPrice;
	item.itemDiscountPrice = itemDiscountPrice;

	ItemsManager::addItem(item);
}

void ProductManager::updateProduct() {
	Item item;
	string itemName;
	int stockCount;
	double itemPrice;
	double itemDiscountPrice;

	cout << "Enter the name of the product to update: ";
	cin >> itemName;
	cout << "Enter the new stock count: ";
	cin >> stockCount;
	cout << "Enter the new price of the product: ";
	cin >> itemPrice;
	cout << "Enter the new discounted price of the product: ";
	cin >> itemDiscountPrice;

	ItemsManager::removeItem(itemName);

	strcpy_s(item.itemName, itemName.c_str());
	item.stockCount = stockCount;
	item.itemPrice = itemPrice;
	item.itemDiscountPrice = itemDiscountPrice;

	ItemsManager::addItem(item);
}

void ProductManager::removeProduct() {
	string itemName;
	cout << "Enter the name of the product to delete: ";
	cin >> itemName;

	ItemsManager::removeItem(itemName);
}

void ProductManager::saveProducts() {
	ItemsManager::saveItemsToFile();
}