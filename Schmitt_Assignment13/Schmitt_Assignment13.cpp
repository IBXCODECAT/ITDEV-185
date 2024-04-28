#include "FileViewer.h"
#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, filename); // Allowing for spaces in the file name

    displayFileContents(filename);

    return 0;
}
