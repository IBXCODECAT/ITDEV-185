#pragma once
#ifndef MENUITEM_H
#define MENUITEM_H

#include <vector>
#include <string>

class MenuItem {
public:
    std::string label;
    std::vector<MenuItem*> children;

    MenuItem(std::string lbl);
    ~MenuItem();
};

#endif // MENUITEM_H
