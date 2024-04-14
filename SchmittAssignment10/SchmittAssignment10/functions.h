#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "contact.h"

void createSampleContactsFile();
void readFromFile(Contact contacts[]);
void displayEntry(Contact contact);
void searchContacts(Contact contacts[], char searchName[]);

#endif
