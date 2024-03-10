#include <iostream>
#include <vector>
#include <limits>
#include "Item.h"
#include "FreshProduce.h"
#include "MeasuredProduct.h"

/// <summary>
/// Utility function to clear the console
/// </summary>
void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence for clearing console
}

/// <summary>
/// Utility function to clear the input buffer
/// </summary>
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// <summary>
/// Suspends program execution (Press enter to continue...)
/// </summary>
void suspendExecution()
{
    int x;
    std::cout << "Enter to continue...";
    clearInputBuffer();
    clearConsole();
}

/// <summary>
/// Provides input validation (integers)
/// </summary>
/// <returns>An integer if provided</returns>
int getIntInput() {
    int input;
    while (true) {
        if (std::cin >> input) {
            clearInputBuffer();
            return input;
        }
        else {
            std::cout << "Invalid input. Please enter a valid number: ";
            clearInputBuffer();
        }
    }
}

/// <summary>
/// Provides input valdiation (doubles)
/// </summary>
/// <returns>A double if provided</returns>
double getDoubleInput() {
    double input;
    while (true) {
        if (std::cin >> input) {
            clearInputBuffer();
            return input;
        }
        else {
            std::cout << "Invalid input. Please enter a valid number: ";
            clearInputBuffer();
        }
    }
}

/// <summary>
/// Displays welcome message
/// </summary>
void displayWelcomeMessage() {
    std::cout << "Welcome to the Online Grocery Store!\n";
}

/// <summary>
/// Displays delivery options
/// </summary>
void displayDeliveryOptions() {
    std::cout << "Please choose an option:\n";
    std::cout << "1. Delivery (with a $20 fee and $5 tip)\n";
    std::cout << "2. Pickup\n";
}

/// <summary>
/// Displays the main menu
/// </summary>
void displayMainMenu() {
    clearConsole();
    std::cout << "Main Menu:\n"
        "1. Fresh Produce\n"
        "2. Meat and Seafood\n"
        "3. Frozen Foods\n"
        "4. Check Out\n"
        "5. Exit\n";
}

/// <summary>
/// Handles delivery options selection
/// </summary>
/// <param name="deliveryOption">Choice</param>
void handleDeliveryChoice(bool& deliveryOption) {
    int deliveryChoice;
    std::cin >> deliveryChoice;
    clearInputBuffer();

    if (deliveryChoice == 1) {
        deliveryOption = true;
    }
}

/// <summary>
/// Method to handle the user's selection of fresh produce.
/// </summary>
/// <param name="cart">Vector of item pointers representing the user's shopping cart.</param>
void handleFreshProduceSelection(std::vector<Item*>& cart) {
    clearConsole();
    std::cout << "Fresh Produce:\n"
        "1. Gala apples $3.99/lb\n"
        "2. Banana $0.48/lb\n"
        "3. Grapes $2.99/lb\n"
        "4. Return to Main Menu\n";

    int produceChoice;
    std::cin >> produceChoice;
    clearInputBuffer();

    switch (produceChoice) {
    case 1: {
        double weight;
        std::cout << "Enter weight (in pounds) for Gala apples: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Gala apples", 3.99, weight));
        break;
    }
    case 2: {
        double weight;
        std::cout << "Enter weight (in pounds) for Banana: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Banana", 0.48, weight));
        break;
    }
    case 3: {
        double weight;
        std::cout << "Enter weight (in pounds) for Grapes: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Grapes", 2.99, weight));
        break;
    }
    case 4:
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

/// <summary>
/// Method to handle the user's selection of meat and seafood.
/// </summary>
/// <param name="cart">Vector of item pointers representing the user's shopping cart.</param>
void handleMeatSeafoodSelection(std::vector<Item*>& cart) {
    clearConsole();
    std::cout << "Meat and Seafood:\n"
        "1. Whole chicken $6.99/lb\n"
        "2. Ground beef $4.99/lb\n"
        "3. Salmon $9.99/lb\n"
        "4. Return to Main Menu\n";

    int meatChoice;
    std::cin >> meatChoice;
    clearInputBuffer();

    switch (meatChoice) {
    case 1: {
        double weight;
        std::cout << "Enter weight (in pounds) for Whole chicken: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Whole chicken", 6.99, weight));
        break;
    }
    case 2: {
        double weight;
        std::cout << "Enter weight (in pounds) for Ground beef: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Ground beef", 4.99, weight));
        break;
    }
    case 3: {
        double weight;
        std::cout << "Enter weight (in pounds) for Salmon: ";
        std::cin >> weight;
        cart.push_back(new FreshProduce("Salmon", 9.99, weight));
        break;
    }
    case 4:
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

/// <summary>
/// Method to handle the user's selection of frozen foods.
/// </summary>
/// <param name="cart">Vector of item pointers representing the user's shopping cart.</param>
void handleFrozenFoodsSelection(std::vector<Item*>& cart) {
    clearConsole();
    std::cout << "Frozen Foods:\n"
        "1. Waffles $6.99\n"
        "2. Pizza $4.99\n"
        "3. Popsicle $2.99\n"
        "4. Return to Main Menu\n";

    int frozenChoice;
    std::cin >> frozenChoice;
    clearInputBuffer();

    switch (frozenChoice) {
    case 1:
        cart.push_back(new MeasuredProduct("Waffles", 6.99, 1));
        break;
    case 2:
        cart.push_back(new MeasuredProduct("Pizza", 4.99, 1));
        break;
    case 3:
        cart.push_back(new MeasuredProduct("Popsicle", 2.99, 1));
        break;
    case 4:
        break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

/// <summary>
/// Main method to run the program.
/// </summary>
int main() {
    std::vector<Item*> cart;
    bool deliveryOption = false;

    displayWelcomeMessage();
    displayDeliveryOptions();
    handleDeliveryChoice(deliveryOption);

    while (true) {
        displayMainMenu();

        int choice = getIntInput();

        if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        }

        switch (choice) {
        case 1:
            handleFreshProduceSelection(cart);
            break;
        case 2:
            handleMeatSeafoodSelection(cart);
            break;
        case 3:
            handleFrozenFoodsSelection(cart);
            break;
        case 4: {
            double totalPrice = 0.0;
            clearConsole();
            std::cout << "--- Your Cart ---\n";
            for (Item* item : cart) {
                std::cout << item->getName() << ": $" << item->calculatePrice() << std::endl;
                totalPrice += item->calculatePrice();
            }

            if (!cart.empty() && deliveryOption) {
                totalPrice += Item::delivery + Item::tip;
                std::cout << "Delivery Fee: $" << Item::delivery << std::endl;
                std::cout << "Tip: $" << Item::tip << std::endl;
            }

            std::cout << "\nTotal Price: $" << totalPrice << std::endl;

            suspendExecution();

            // Clear cart after checkout
            for (Item* item : cart) {
                delete item;
            }
            cart.clear();
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
