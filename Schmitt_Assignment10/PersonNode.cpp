#include "PersonNode.h"

// Constructors
PersonNode::PersonNode() : next(nullptr) {}
PersonNode::PersonNode(string firstName, string lastName, string addr, string phoneNumber, PersonNode* nextNode)
    : fName(firstName), lName(lastName), address(addr), phone(phoneNumber), next(nextNode) {}

// Getters
string PersonNode::getFName() const { return fName; }
string PersonNode::getLName() const { return lName; }
string PersonNode::getAddress() const { return address; }
string PersonNode::getPhone() const { return phone; }
string PersonNode::getFullName() const { return lName + ", " + fName; }
PersonNode* PersonNode::getNext() const { return next; }

// Setters
void PersonNode::setFName(string firstName) { fName = firstName; }
void PersonNode::setLName(string lastName) { lName = lastName; }
void PersonNode::setAddress(string addr) { address = addr; }
void PersonNode::setPhone(string phoneNumber) { phone = phoneNumber; }
void PersonNode::setNext(PersonNode* nextNode) { next = nextNode; }
