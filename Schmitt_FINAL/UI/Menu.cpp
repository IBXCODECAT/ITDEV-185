#include "Menu.hpp"
#include <iostream>
#include <thread>
#include <limits>
#include <chrono>
#include <stack> // Include stack for managing menu layers

constexpr auto ERROR_DISPLAY_TIME_MS = 1500;

Menu::Menu() {
    root = new MenuItem("Root");
    current = root;
    previous = nullptr;
    menuStack.push(root); // Push root menu onto the stack
}

Menu::~Menu() {
    delete root;
}

void Menu::addChild(std::string label) {
    MenuItem* child = new MenuItem(label);
    current->children.push_back(child);
}

void Menu::display() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::cout << "Current Menu: " << current->label << std::endl;
    int index = 1;

    // Display "Go Back" as the first option if there's a previous menu
    if (menuStack.size() > 1) {
        std::cout << "[0] Go Back" << std::endl;
        index++;
    }
    else
    {
        std::cout << "[0] Exit" << std::endl;
    }

    for (MenuItem* child : current->children) {

        unsigned short DISPLAY_INDEX = index;

        if (menuStack.size() > 1) DISPLAY_INDEX--; // Adjust the display index if "Go Back" is displayed

        std::cout << '[' << DISPLAY_INDEX << "] " << child->label << std::endl;
        index++;
    }
}

void Menu::navigate(int choice) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        printError("Invalid input. Please enter a number corresponding to a menu option.");
        std::this_thread::sleep_for(std::chrono::milliseconds(ERROR_DISPLAY_TIME_MS));

        return;
    }

    if (choice == 0 && menuStack.size() > 1) {
        menuStack.pop(); // Pop the current menu from the stack
        current = menuStack.top(); // Update the current menu to the one on top of the stack
        previous = menuStack.size() > 1 ? menuStack.top() : nullptr; // Update previous menu if applicable
    }
    else if(choice == 0 && menuStack.size() == 1)
    {
        return exit(0);
    }
    else if (choice >= 1 && choice <= current->children.size()) {
        previous = current;
        current = current->children[choice - 1];
        menuStack.push(current); // Push the selected menu onto the stack
    }
    else {
        printError("Invalid choice! Please enter a valid number corresponding to a menu option.");
        std::this_thread::sleep_for(std::chrono::milliseconds(ERROR_DISPLAY_TIME_MS));
    }
}

#ifdef _WIN32
#include <windows.h>
#endif

void Menu::printError(const std::string message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << message << std::endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    std::cout << "\033[31m" + message + "\033[0m" << std::endl;
#endif
}

void Menu::goBack() {
    if (menuStack.size() > 1) {
        menuStack.pop(); // Pop the current menu from the stack
        current = menuStack.top(); // Update the current menu to the one on top of the stack
        previous = menuStack.size() > 1 ? menuStack.top() : nullptr; // Update previous menu if applicable
    }
}
