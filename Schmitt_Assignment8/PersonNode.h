#pragma once

#ifndef PERSONNODE_H
#define PERSONNODE_H

#include <string>
using namespace std;

class PersonNode {
private:
    string fName;
    string lName;
    string address;
    string phone;
    PersonNode* next;

public:
    // Constructors
    PersonNode();
    PersonNode(string firstName, string lastName, string addr, string phoneNumber, PersonNode* nextNode = nullptr);

    // Getters
    string getFName() const;
    string getLName() const;
    string getAddress() const;
    string getPhone() const;
    string getFullName() const;
    PersonNode* getNext() const;

    // Setters
    void setFName(string firstName);
    void setLName(string lastName);
    void setAddress(string addr);
    void setPhone(string phoneNumber);
    void setNext(PersonNode* nextNode);
};

#endif
