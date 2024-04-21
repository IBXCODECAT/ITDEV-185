#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "PersonNode.h"

class LinkedList {
private:
    PersonNode* headPtr;
    PersonNode* tailPtr;

public:
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Function to add a contact
    void addLink(const PersonNode& newPerson);

    // Function to find the spot to insert a new node
    PersonNode* findInsertSpot(const PersonNode* newNode) const;

    // Getter for headPtr
    PersonNode* getHeadPtr() const;

    // Getter for tailPtr
    PersonNode* getTailPtr() const;

    // Setter for headPtr
    void setHeadPtr(PersonNode* newHeadPtr);

    // Setter for tailPtr
    void setTailPtr(PersonNode* newTailPtr);
};

#endif
