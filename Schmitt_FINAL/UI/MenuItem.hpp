#pragma once
#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

class MenuItem {
public:
    std::string label;
    std::vector<MenuItem*> children;

    MenuItem(std::string lbl);
    virtual ~MenuItem(); // Add virtual destructor
    virtual bool isOption() const { return false; } // Add a virtual function to check if it's an option
};

#endif // MENUITEM_H