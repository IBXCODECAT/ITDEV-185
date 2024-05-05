#include <iostream>

#include "Item.hpp";

using namespace std;
using json = nlohmann::json;

Item::Item() {}

Item::Item(int stockCount, double itemPrice, double itemDiscountPrice)
    : stockCount(stockCount), itemPrice(itemPrice), itemDiscountPrice(itemDiscountPrice) {}

void Item::fromJson(const string& jsonString) {
    json jsonObject = json::parse(jsonString);
    stockCount = jsonObject["stockCount"].get<int>();
    itemPrice = jsonObject["itemPrice"].get<double>();
    itemDiscountPrice = jsonObject["itemDiscountPrice"].get<double>();
}

string Item::toJson() const {
    json jsonObject = {
        {"stockCount", stockCount},
        {"itemPrice", itemPrice},
        {"itemDiscountPrice", itemDiscountPrice}
    };
    return jsonObject.dump();
}

void Item::print() const  {
	cout << "Stock Count: " << stockCount << endl;
	cout << "Item Price: " << itemPrice << endl;
	cout << "Item Discount Price: " << itemDiscountPrice << endl;
}
