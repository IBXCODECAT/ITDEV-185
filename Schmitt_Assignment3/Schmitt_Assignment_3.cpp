#include <iostream>
#include <iomanip>

// Constants
const double SPOOL_PRICE = 100.00;
const double SHIPPING_RATE = 10.00;

// Function prototypes
void getOrderData(int& spoolsOrdered, int& spoolsInStock, double& specialCharges);
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, double specialCharges = SHIPPING_RATE);

int main() {
    // Variables to store order data
    int spoolsOrdered, spoolsInStock;
    double specialCharges;

    // Function call to get order data
    getOrderData(spoolsOrdered, spoolsInStock, specialCharges);

    // Function call to display order status
    displayOrderStatus(spoolsOrdered, spoolsInStock, specialCharges);

    return 0;
}

// Function to get order data
void getOrderData(int& spoolsOrdered, int& spoolsInStock, double& specialCharges) {
    std::cout << "Enter the number of spools ordered: ";
    std::cin >> spoolsOrdered;

    std::cout << "Enter the number of spools in stock: ";
    std::cin >> spoolsInStock;

    std::cout << "Enter any special shipping and handling charges (0 for none): ";
    std::cin >> specialCharges;
}

// Function to display order status
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, double specialCharges) {
    int backOrder = (spoolsOrdered > spoolsInStock) ? spoolsOrdered - spoolsInStock : 0;
    int readyToShip = spoolsOrdered - backOrder;

    double totalSellingPrice = readyToShip * SPOOL_PRICE;
    double totalShippingCharges = (readyToShip * SHIPPING_RATE) + (readyToShip * specialCharges);

    double totalOrder = totalSellingPrice + totalShippingCharges    ;

    // Displaying formatted output
    std::cout << std::endl << std::endl;
    std::cout << "  *** Order Summmary ***  \n";
    std::cout << "--------------------------\n";
    std::cout << std::setw(30) << std::left << "Spools ordered: " << spoolsOrdered << "\n";
    std::cout << std::setw(30) << std::left << "Spools ready to ship: " << readyToShip << "\n";
    if(spoolsOrdered > spoolsInStock) std::cout << std::setw(30) << std::left << "Backordered spools: " << backOrder << "\n" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "   *** Order Status ***   \n";
    std::cout << "--------------------------\n";
    std::cout << std::setw(30) << std::left << "Total selling price:        $" << std::fixed << std::setprecision(2) << totalSellingPrice << "\n";
    std::cout << std::setw(30) << std::left << "Total shipping charges:     $" << totalShippingCharges << "\n";
    std::cout << std::setw(30) << std::left << "Total order ready to ship:  $" << totalOrder << "\n";
}
