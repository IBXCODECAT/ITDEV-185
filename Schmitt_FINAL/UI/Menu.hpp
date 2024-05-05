#pragma once
#ifndef MENU_H
#define MENU_H

#include "MenuItem.hpp"
#include <stack> // Include stack for managing menu layers

class Menu {
private:
    MenuItem* root;
    MenuItem* current;
    MenuItem* previous; // Keep track of the previous menu
    std::stack<MenuItem*> menuStack; // Stack to manage menu layers

    void printError(const std::string message);

public:
    Menu();
    ~Menu();
    void addChild(std::string label);
    void display();
    void navigate(int choice);
    void goBack();
};

#endif // MENU_H
