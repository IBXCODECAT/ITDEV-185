#include "contact.h"
#include <cstring>

Contact::Contact() {}

char* Contact::getFirstName() { return firstName; }
char* Contact::getFullName() { return fullName; }
char* Contact::getLastName() { return lastName; }
char* Contact::getPhone() { return phone; }

void Contact::setFirstName(const char* fName) { strcpy_s(firstName, 20, fName); }
void Contact::setFullName(const char* fName) { strcpy_s(fullName, 40, fName); }
void Contact::setLastName(const char* lName) { strcpy_s(lastName, 20, lName); }
void Contact::setPhone(const char* phoneNumber) { strcpy_s(phone, 14, phoneNumber); }
