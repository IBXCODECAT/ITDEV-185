#pragma once

#ifndef SHOPPINGMANAGER_H
#define SHOPPINGMANAGER_H

#include <iostream>
#include "Cart.hpp"
#include "ItemsManager.hpp"

class ShoppingManager {
public:
    static void addItems();
    static void removeItems();
    static void listItems();
    static void finishAndPay();
};

#endif // SHOPPINGMANAGER_H