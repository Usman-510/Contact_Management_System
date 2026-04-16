#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <vector>
#include "Contact.h"

class ContactBook {
private:
    vector<Contact> contacts;
    string filename = "contacts.txt";

public:
    void load();
    void save();

    void addContact();
    void showContacts();
    void searchContact();
    void deleteContact();
    void editContact();
};

#endif