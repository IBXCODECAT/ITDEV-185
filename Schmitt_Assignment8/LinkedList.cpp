#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : headPtr(nullptr), tailPtr(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    PersonNode* current = headPtr;
    while (current != nullptr) {
        PersonNode* next = current->getNext();
        delete current;
        current = next;
    }
    headPtr = tailPtr = nullptr;
}

// Function to add a contact
void LinkedList::addLink(const PersonNode& newPerson) {
    PersonNode* newNode = new PersonNode(newPerson);
    if (headPtr == nullptr) {
        headPtr = tailPtr = newNode;
    }
    else {
        PersonNode* insertSpot = findInsertSpot(newNode);
        if (insertSpot == nullptr) {
            newNode->setNext(headPtr);
            headPtr = newNode;
        }
        else {
            newNode->setNext(insertSpot->getNext());
            insertSpot->setNext(newNode);
            if (insertSpot == tailPtr)
                tailPtr = newNode;
        }
    }
}

// Function to find the spot to insert a new node
PersonNode* LinkedList::findInsertSpot(const PersonNode* newNode) const {
    PersonNode* current = headPtr;
    PersonNode* prev = nullptr;
    while (current != nullptr && current->getLName() < newNode->getLName()) {
        prev = current;
        current = current->getNext();
    }
    return prev;
}

// Getter for headPtr
PersonNode* LinkedList::getHeadPtr() const {
    return headPtr;
}

// Getter for tailPtr
PersonNode* LinkedList::getTailPtr() const {
    return tailPtr;
}

// Setter for headPtr
void LinkedList::setHeadPtr(PersonNode* newHeadPtr) {
    headPtr = newHeadPtr;
}

// Setter for tailPtr
void LinkedList::setTailPtr(PersonNode* newTailPtr) {
    tailPtr = newTailPtr;
}