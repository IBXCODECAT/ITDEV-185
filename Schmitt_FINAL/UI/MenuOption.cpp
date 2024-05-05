#include "MenuOption.hpp"

MenuOption::MenuOption(std::string lbl, Callback cb) : MenuItem(lbl), callback(cb) {}

MenuOption::~MenuOption() {}

void MenuOption::executeCallback() const {
    if (callback != nullptr) {
        callback();
    }
}
