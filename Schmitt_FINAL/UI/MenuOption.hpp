#pragma once
#ifndef MENUOPTION_H
#define MENUOPTION_H

#include "MenuItem.hpp"
#include <string>
#include <vector>

class MenuOption : public MenuItem {
public:
    typedef void (*Callback)();

    MenuOption(std::string lbl, Callback cb);
    ~MenuOption();

    void executeCallback() const;
    
    bool isOption() const override { return true; }

private:
    Callback callback;
};

#endif // MENUOPTION_H