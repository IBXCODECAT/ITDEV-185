#include "Item.hpp"
#include <cstring> // For strcpy
#include <iostream>

using namespace std;
using json = nlohmann::json;

Item::Item() {}

Item::Item(const char* itemName, const char* itemCategory, int stockCount, double itemPrice, double itemDiscountPrice):
    stockCount(stockCount), itemPrice(itemPrice), itemDiscountPrice(itemDiscountPrice)
{
    strncpy_s(this->itemName, itemName, sizeof(this->itemName) - 1);
    this->itemName[sizeof(this->itemName) - 1] = '\0'; // Ensure null-termination

	strncpy_s(this->itemCategory, itemCategory, sizeof(this->itemCategory) - 1);
	this->itemCategory[sizeof(this->itemCategory) - 1] = '\0'; // Ensure null-termination
}

void Item::fromJson(const string& jsonString) {
    json jsonObject = json::parse(jsonString);
    strncpy_s(itemName, jsonObject["itemName"].get<string>().c_str(), sizeof(itemName) - 1);
	strncpy_s(itemCategory, jsonObject["itemCategory"].get<string>().c_str(), sizeof(itemCategory) - 1);
    itemName[sizeof(itemName) - 1] = '\0'; // Ensure null-termination
    stockCount = jsonObject["stockCount"].get<int>();
    itemPrice = jsonObject["itemPrice"].get<double>();
    itemDiscountPrice = jsonObject["itemDiscountPrice"].get<double>();
}

string Item::toJson() const {
    json jsonObject = {
        {"itemName", itemName},
		{"itemCategory", itemCategory},
        {"stockCount", stockCount},
        {"itemPrice", itemPrice},
        {"itemDiscountPrice", itemDiscountPrice}
    };
    return jsonObject.dump();
}

void Item::print() const {
	cout << "Item Name: " << itemName << endl;
	cout << "Item Category: " << itemCategory << endl;
	cout << "Stock Count: " << stockCount << endl;
	cout << "Item Price: " << itemPrice << endl;
	cout << "Item Discount Price: " << itemDiscountPrice << endl;
}