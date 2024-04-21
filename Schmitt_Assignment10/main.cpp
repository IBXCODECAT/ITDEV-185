#include <iostream>
#include <cstdlib> // For system("cls") on Windows and system("clear") on Unix-like systems
#include "LinkedList.h"
#include "PersonNode.h"
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-like systems
#endif
}

void displayDirectory(const LinkedList& contactBook) {
    cout << "Contact Directory:\n";
    PersonNode* current = contactBook.getHeadPtr();
    while (current != nullptr) {
        cout << "Name: " << current->getFullName() << endl;
        cout << "Address: " << current->getAddress() << endl;
        cout << "Phone: " << current->getPhone() << endl;
        cout << endl;
        current = current->getNext();
    }
}

void searchName(const LinkedList& contactBook) {
    string searchName;
    cout << "Enter the name to search for: ";
    cin.ignore();
    getline(cin, searchName);

    PersonNode* current = contactBook.getHeadPtr();
    bool found = false;
    while (current != nullptr) {
        if (current->getFullName() == searchName) {
            cout << "Name: " << current->getFullName() << endl;
            cout << "Address: " << current->getAddress() << endl;
            cout << "Phone: " << current->getPhone() << endl;
            found = true;
            break;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "Name not found in the directory. Retry your search using <Lastname, Firstname>?\n";
    }
}

void removeContact(LinkedList& contactBook) {
    string removeName;
    cout << "Enter the name to remove: ";
    cin.ignore();
    getline(cin, removeName);

    PersonNode* current = contactBook.getHeadPtr();
    PersonNode* prev = nullptr;
    bool found = false;
    while (current != nullptr) {
        if (current->getFullName() == removeName) {
            if (current == contactBook.getHeadPtr()) {
                contactBook.setHeadPtr(current->getNext());
            }
            else {
                prev->setNext(current->getNext());
            }
            if (current == contactBook.getTailPtr()) {
                contactBook.setTailPtr(prev);
            }
            delete current;
            cout << "Contact removed successfully.\n";
            found = true;
            break;
        }
        prev = current;
        current = current->getNext();
    }
    if (!found) {
        cout << "Name not found in the directory. Retry your search using <Lastname, Firstname>?\n";
    }
}

int main() {
    LinkedList contactBook;

    while (true) {
        clearScreen();
        cout << "Contact Book Menu\n";
        cout << "1. Add a person to the directory\n";
        cout << "2. Display directory\n";
        cout << "3. Search for a name\n";
        cout << "4. Remove someone from the directory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        clearScreen();

        switch (choice) {
        case 1: {
            string firstName, lastName, address, phone;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter phone: ";
            cin >> phone;

            try {
                // Check if phone number is valid
                if (phone.length() != 10) {
                    throw invalid_argument("Invalid phone number: must be 10 digits.");
                }

                PersonNode newPerson(firstName, lastName, address, phone);
                contactBook.addLink(newPerson);
                cout << "Contact added successfully.\n";
            }
            catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        }
        case 2:
            displayDirectory(contactBook);
            break;
        case 3:
            searchName(contactBook);
            break;
        case 4:
            removeContact(contactBook);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        // Wait for user to press Enter before continuing
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
