#include "MenuItem.hpp"

MenuItem::MenuItem(std::string lbl) : label(lbl) {}

MenuItem::~MenuItem() {
    for (MenuItem* child : children) {
        delete child;
    }
}