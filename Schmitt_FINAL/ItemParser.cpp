#include <iostream>
#include <fstream>
#include <string>

#include "Item.hpp";
#include "ItemParser.hpp"

using namespace std;
using json = nlohmann::json;

void ItemParser::readFromFile(const string& filename, Item& obj) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    json jsonData;
    file >> jsonData;
    file.close();

    obj.fromJson(jsonData.dump());
}

void ItemParser::writeToFile(const string& filename, const Item& obj) {
    json jsonData = json::parse(obj.toJson());

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << jsonData;
    file.close();
}
