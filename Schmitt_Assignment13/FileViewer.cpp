#include "FileViewer.h"
#include <iostream>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void displayFileContents(const std::string& filename) {
    const unsigned short NUMBER_OF_LINES_TO_READ = 20;

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "File does not exist." << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        lineCount++;

        if (lineCount == NUMBER_OF_LINES_TO_READ) {
            std::cout << "Press Enter to continue...";
            std::cin.ignore(); // Wait for user to press Enter
            system(CLEAR_SCREEN); // Clear the screen
            lineCount = 0; // Reset line count
        }
    }

    file.close();
}
