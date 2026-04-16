#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact();
    Contact(string n, string p, string e);
};

#endif