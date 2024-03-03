#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Name [Nathan Schmitt]
    // Course Number: [ITDEV-185]
    // Assignment Number: 1

    // Get input from the user
    cout << "Enter the month: ";
    string month;
    getline(cin, month);

    cout << "Enter the year: ";
    int year;
    cin >> year;

    cout << "Enter the amount collected at the cash register: $";
    double totalAmount;
    cin >> totalAmount;

    // Calculate sales tax
    double stateTaxRate = 0.04;
    double countyTaxRate = 0.02;

    double stateSalesTax = totalAmount * stateTaxRate;
    double countySalesTax = totalAmount * countyTaxRate;
    double totalSalesTax = stateSalesTax + countySalesTax;

    // Display information with requested formatting
    cout << "\nMonthly Sales Tax Report" << endl;
    cout << "Month: " << setw(9) << month << "  " << year << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Sales:\t\t\t" << setw(12) << "$" << totalAmount << endl;
    cout << "Total Collected:\t" << setw(12) << "$" << totalAmount + totalSalesTax << endl;
    cout << "County Sales Tax:\t" << setw(12) << "$" << countySalesTax << endl;
    cout << "State Sales Tax:\t" << setw(12) << "$" << stateSalesTax << endl;
    cout << "Total Sales Tax:\t" << setw(12) << "$"  << totalSalesTax << endl;


    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cin.get(); // Keep console open
    return 0;
}