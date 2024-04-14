#include <iostream>
#include <cstdlib>
#include "contact.h"
#include "functions.h"

using namespace std;

int main() {
    char choice;
    createSampleContactsFile();

    Contact contacts[10];
    readFromFile(contacts);

    do {
        cout << "Press S to search for a contact or E to exit: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
        case 'S':
        case 's':
        {
            char searchName[40];
            cout << "Enter the last name to search: ";
            cin.getline(searchName, 40);
            searchContacts(contacts, searchName);
            system("pause");
            system("cls");
            break;
        }
        case 'E':
        case 'e':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'E' && choice != 'e');

    return 0;
}
