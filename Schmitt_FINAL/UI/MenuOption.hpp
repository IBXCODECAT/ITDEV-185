#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef MENUOPTION_H
#define MENUOPTION_H

// Include statements
#include <string>
#include <vector>

// Include local headers
#include "MenuItem.hpp"

/// <summary>
/// Menu option class to represent a menu item that is an option.
/// </summary>
class MenuOption : public MenuItem {
public:

    /// <summary>
	/// Type definition for the callback function.
	/// This function is called when the option is selected.
    /// </summary>
    typedef void (*Callback)();

    /// <summary>
	/// Construct a menu option with a label and a callback function.
    /// </summary>
    /// <param name="lbl">The label for this option</param>
    /// <param name="cb">The callback funciton to execute when this option is selected</param>
    MenuOption(std::string lbl, Callback cb);

    /// <summary>
	/// Destructor for the menu option.
    /// </summary>
    ~MenuOption();

    /// <summary>
	/// Executes the callback function associated with this option.
    /// </summary>
    void executeCallback() const;
    
    /// <summary>
	/// Check if the menu item is an option or a child menu.
    /// </summary>
    /// <returns>True if the type is an option</returns>
    bool isOption() const override { return true; }

private:
    /// <summary>
	/// Callback function to execute when the option is selected.
    /// </summary>
    Callback callback;
};

#endif // MENUOPTION_H