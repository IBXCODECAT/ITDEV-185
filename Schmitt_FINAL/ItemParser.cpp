#include <iostream>
#include <fstream>
#include <string>

#include "Item.hpp"
#include "ItemParser.hpp"

#ifdef _WIN32
#include <direct.h> // For Windows
#define MKDIR(directory) _mkdir(directory)
#else
#include <sys/stat.h> // For Unix-like systems
#define MKDIR(directory) mkdir(directory, 0777)
#endif

#define ITEMS_SUBDIRECTORY "items"
#define DEBUG_FLAG false

using namespace std;
using json = nlohmann::json;

void ItemParser::ensureItemsDirectoryExists() {
    // Check if the items directory exists, if not, create it
    if (!directoryExists(ITEMS_SUBDIRECTORY)) {
        if (MKDIR(ITEMS_SUBDIRECTORY) != 0) {

            if (DEBUG_FLAG) cout << "Error creating directory: " << ITEMS_SUBDIRECTORY << endl;

            cerr << "Error creating directory: " << ITEMS_SUBDIRECTORY << endl;
            cerr << "Error code: " << errno << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        
        if (DEBUG_FLAG) cout << "Items directory created: " << ITEMS_SUBDIRECTORY << endl;

    }
    else {
        if (DEBUG_FLAG) cout << "Items directory already exists: " << ITEMS_SUBDIRECTORY << endl;
    }
}

bool ItemParser::directoryExists(const std::string& directory) {
    struct stat info;
    if (stat(directory.c_str(), &info) != 0) {
        if (DEBUG_FLAG) cout << "Directory does not exist: " << directory << endl;
        return false;
    }

    if (DEBUG_FLAG) cout << "Directory exists: " << directory << endl;
    return (info.st_mode & S_IFDIR) != 0;
}


Item ItemParser::readFromFile(const string itemName) {
    // Ensure the items directory exists
    ensureItemsDirectoryExists();

    // Construct the filename using the itemName and add ".item" extension
    string filename = ITEMS_SUBDIRECTORY;  // No need to concatenate yet
    filename += "/" + itemName + ".item";  // Now concatenate with the itemName and ".item" extension

    // Open the file for reading
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        cerr << "Make sure the file is not open by another program." << endl;
        cerr << "Exiting..." << endl;
        // Return a default-constructed Item object or handle the error appropriately
        return Item(); // Return a default-constructed Item object
    }

    json jsonData;
    file >> jsonData;
    file.close();

    Item item;
    item.fromJson(jsonData.dump());
    return item;
}

void ItemParser::writeToFile(const Item& obj) {
    // Ensure the items directory exists
    ensureItemsDirectoryExists();

    // Construct the filename using the item name and add ".item" extension
    string filename(obj.itemName);
    string filepath = ITEMS_SUBDIRECTORY; // No need to concatenate yet
    filepath += "/" + filename + ".item"; // Now concatenate with the filename and ".item" extension

    // Open the file for writing
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        cerr << "Make sure the file is not open by another program." << endl;
        cerr << "Exiting..." << endl;
        return;
    }

    // Write the JSON data to the file
    json jsonData = json::parse(obj.toJson());
    file << jsonData;
    file.close();
}
