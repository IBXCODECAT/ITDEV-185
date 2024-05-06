#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef MENU_H
#define MENU_H

// Include statements
#include <stack>

// Include local headers
#include "MenuItem.hpp"
#include "MenuOption.hpp"

/// <summary>
/// Class to represent a menu.
/// </summary>
class Menu {
private:
    MenuItem* root; /**< Pointer to the root menu item. */
    MenuItem* current; /**< Pointer to the current menu item. */
    MenuItem* previous; /**< Pointer to the previous menu item. */
    std::stack<MenuItem*> menuStack; /**< Stack to track menu navigation. */

    /// <summary>
	/// Prints an error message.
    /// </summary>
    /// <param name="message">The error message to be printed</param>
    void printError(const std::string message);

    /// <summary>
	/// Processes the selected option.
    /// </summary>
    /// <param name="choice">The user's choice</param>
    void processOption(int choice);

public:
    /// <summary>
	/// Default constructor.
    /// </summary>
    Menu();

    /// <summary>
	/// Destructor.
    /// </summary>
    ~Menu();

    /// <summary>
	/// Adds a child menu item.
    /// </summary>
    /// <param name="label">The label of the child menu item</param>
    void addChild(std::string label);

    /// <summary>
	/// Adds an option with a callback function.
    /// </summary>
    /// <param name="label">The label ;of the option</param>
    /// <param name="cb">The callback function to associate with the option when it is selected</param>
    void addOption(std::string label, MenuOption::Callback cb);

    /// <summary>
	/// Displays the menu at its current state.
    /// </summary>
    void display();

    /// <summary>
	/// Navigates to the selected menu item.
    /// </summary>
    /// <param name="choice">The user's choice</param>
    void navigate(int choice);

    /// <summary>
	/// Navigate to the previous menu.
    /// </summary>
    void goBack();
};

#endif // MENU_H
