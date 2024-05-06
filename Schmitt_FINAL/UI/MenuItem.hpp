#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#ifndef MENUITEM_H
#define MENUITEM_H

// Include statements
#include <string>
#include <vector>

/// <summary>
/// Class to represent a menu item in a menu.
/// </summary>
class MenuItem {
public:
    /// <summary>
	/// The label of the menu item.
    /// </summary>
    std::string label;

    /// <summary>
	/// The children of the menu item.
    /// </summary>
    std::vector<MenuItem*> children;

    /// <summary>
	/// Constructs a menu item with a label.
    /// </summary>
    /// <param name="lbl">The label to associate with this menu item</param>
    MenuItem(std::string lbl);
    
    /// <summary>
	/// Destructor for the menu item.
    /// </summary>
    virtual ~MenuItem();

    /// <summary>
	/// Check if the menu item is an option or a child menu.
    /// </summary>
    /// <returns>True if the type is an option</returns>
    virtual bool isOption() const { return false; }
};

#endif // MENUITEM_H