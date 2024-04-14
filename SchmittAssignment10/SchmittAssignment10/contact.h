#ifndef CONTACT_H
#define CONTACT_H

class Contact {
private:
    char firstName[20];
    char fullName[40];
    char lastName[20];
    char phone[14];
public:
    Contact();
    char* getFirstName();
    char* getFullName();
    char* getLastName();
    char* getPhone();
    void setFirstName(const char* fName);
    void setFullName(const char* fName);
    void setLastName(const char* lName);
    void setPhone(const char* phoneNumber);
};

#endif
