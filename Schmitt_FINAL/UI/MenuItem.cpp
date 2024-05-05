#include "MenuItem.hpp"
#include "MenuOption.hpp"

MenuItem::MenuItem(std::string lbl) : label(lbl) {}

MenuItem::~MenuItem() {
    for (auto child : children) {
        delete child;
    }
}