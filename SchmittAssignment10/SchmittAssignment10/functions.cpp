#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"

using namespace std;

void createSampleContactsFile() {
    ofstream file("contacts.txt");
    if (!file) {
        cerr << "Unable to create file!" << endl;
        exit(1);
    }

    file << "Smith" << endl << "Mary" << endl << "414-444-4444" << endl;
    file << "Johnson" << endl << "Sara" << endl << "414-555-5555" << endl;
    file << "Smith" << endl << "Kim" << endl << "414-556-6789" << endl;
    file << "Scott" << endl << "Jill" << endl << "262-236-0925" << endl;
    file << "Jackson" << endl << "Derek" << endl << "262-345-6789" << endl;
    file << "Jackson" << endl << "Jack" << endl << "262-435-2847" << endl;
    file << "Bird" << endl << "Larry" << endl << "414-345-3344" << endl;

    file.close();
}

void readFromFile(Contact contacts[]) {
    ifstream file("contacts.txt");
    if (!file) {
        cerr << "Unable to open file!" << endl;
        exit(1);
    }

    for (int i = 0; i < 10; ++i) {
        char lName[40], fName[20], phoneNumber[14];
        file.getline(lName, 40);
        file.getline(fName, 20);
        file.getline(phoneNumber, 14);

        contacts[i].setLastName(lName);
        contacts[i].setFirstName(fName);
        contacts[i].setPhone(phoneNumber);
    }

    file.close();
}

void displayEntry(Contact contact) {
    cout << "Name: " << contact.getFullName() << endl;
    cout << "Phone: " << contact.getPhone() << endl;
    cout << endl;
}

void searchContacts(Contact contacts[], char searchName[]) {
    bool found = false;
    for (int i = 0; i < 10; ++i) {
        if (strcmp(contacts[i].getLastName(), searchName) == 0) {
            displayEntry(contacts[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No matching contacts found." << endl;
    }
}
