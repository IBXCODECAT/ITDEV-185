#include "Menu.hpp"
#include "MenuOption.hpp"

#include <iostream>
#include <thread>
#include <limits>
#include <chrono>

constexpr auto ERROR_DISPLAY_TIME_MS = 1000;

Menu::Menu() {
    root = new MenuItem("Root");
    current = root;
    previous = nullptr;
    menuStack.push(root);
}

Menu::~Menu() {
    delete root;
}

void Menu::addChild(std::string label) {
    MenuItem* child = new MenuItem(label);
    current->children.push_back(child);
}

void Menu::addOption(std::string label, MenuOption::Callback cb) {
    MenuOption* option = new MenuOption(label, cb);
    current->children.push_back(option);
}

void Menu::display() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::cout << "Current Menu: " << current->label << std::endl;
    int index = 1;

    if (menuStack.size() > 1) {
        std::cout << "[0] Go Back" << std::endl;
        index++;
    }

    for (MenuItem* child : current->children) {
        
        if (child->isOption())
        {
            std::cout << '[' << index << "] Option - " << child->label << std::endl;
        }
        else
        {
            std::cout << '[' << index << "] Menu - " << child->label << std::endl;
        }

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
        goBack();
    }
    else if (choice >= 1 && choice <= current->children.size()) {
        processOption(choice);
    }
    else {
        printError("Invalid choice! Please enter a valid number corresponding to a menu option.");
        std::this_thread::sleep_for(std::chrono::milliseconds(ERROR_DISPLAY_TIME_MS));
    }
}

#include "Windows.h";

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
    menuStack.pop();
    current = menuStack.top();
    previous = menuStack.size() > 1 ? menuStack.top() : nullptr;
}

void Menu::processOption(int choice) {
    MenuItem* selected = current->children[choice - 1];
    if (selected->isOption()) {
        MenuOption* option = static_cast<MenuOption*>(selected);
        std::cout << "You selected: " << option->label << std::endl;
        option->executeCallback(); // Execute callback associated with the option
    }
    else {
        previous = current;
        current = selected;
        menuStack.push(current);
    }
}
