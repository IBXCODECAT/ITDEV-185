#pragma once
#ifndef MENU_H
#define MENU_H

#include "MenuItem.hpp"
#include "MenuOption.hpp"

#include <stack>

/**
 * @brief Class representing a menu.
 */
class Menu {
private:
    MenuItem* root; /**< Pointer to the root menu item. */
    MenuItem* current; /**< Pointer to the current menu item. */
    MenuItem* previous; /**< Pointer to the previous menu item. */
    std::stack<MenuItem*> menuStack; /**< Stack to track menu navigation. */

    /**
     * @brief Prints an error message.
     * @param message The error message to be printed.
     */
    void printError(const std::string message);

    /**
     * @brief Processes the selected option.
     * @param choice The user's choice.
     */
    void processOption(int choice);

public:
    /**
     * @brief Default constructor.
     */
    Menu();

    /**
     * @brief Destructor.
     */
    ~Menu();

    /**
     * @brief Adds a child menu item.
     * @param label The label of the child menu item.
     */
    void addChild(std::string label);

    /**
     * @brief Adds an option with a callback function.
     * @param label The label of the option.
     * @param cb The callback function associated with the option.
     */
    void addOption(std::string label, MenuOption::Callback cb);

    /**
     * @brief Displays the current menu.
     */
    void display();

    /**
     * @brief Navigates to the selected menu item.
     * @param choice The user's choice.
     */
    void navigate(int choice);

    /**
     * @brief Navigates to the previous menu.
     */
    void goBack();
};

#endif // MENU_H
