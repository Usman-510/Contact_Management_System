#include "ContactBook.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;


string safeInput(string msg) {
    string s;
    cout << msg;
    getline(cin, s);
    return s;
}


void ContactBook::load() {
    contacts.clear();

    ifstream file(filename);
    string n, p, e;

    while (file >> n >> p >> e) {
        contacts.push_back(Contact(n, p, e));
    }

    file.close();
}

// ---------- SAVE ----------
void ContactBook::save() {
    ofstream file(filename);

    for (auto &c : contacts) {
        file << c.name << " " << c.phone << " " << c.email << endl;
    }

    file.close();
}

// ---------- ADD ----------
void ContactBook::addContact() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Contact c;

    // NAME
    while (true) {
        c.name = safeInput("Enter Name: ");

        bool ok = true;
        for (char ch : c.name)
            if (!isalpha(ch) && ch != ' ')
                ok = false;

        if (ok && c.name != "") break;
        cout << "Invalid Name!\n";
    }

    // PHONE
    while (true) {
        c.phone = safeInput("Enter Phone: ");

        bool ok = true;
        for (char ch : c.phone)
            if (!isdigit(ch))
                ok = false;

        if (ok && c.phone != "") break;
        cout << "Invalid Phone!\n";
    }

    // EMAIL
    while (true) {
        c.email = safeInput("Enter Email: ");

        int at = 0;
        for (char ch : c.email)
            if (ch == '@') at++;

        if (at == 1 && c.email[0] != '@' && c.email.back() != '@')
            break;

        cout << "Invalid Email!\n";
    }

    contacts.push_back(c);
    save();

    cout << "\nContact Added Successfully!\n";
}

// ---------- SHOW ----------
void ContactBook::showContacts() {
    if (contacts.empty()) {
        cout << "\nNo Contacts Found!\n";
        return;
    }

    for (auto &c : contacts) {
        cout << "\nName  : " << c.name;
        cout << "\nPhone : " << c.phone;
        cout << "\nEmail : " << c.email;
        cout << "\n--------------------\n";
    }
}

// ---------- SEARCH ----------
void ContactBook::searchContact() {
    string key;
    cout << "Enter phone: ";
    cin >> key;

    bool found = false;

    for (auto &c : contacts) {
        if (c.phone == key) {
            cout << "\nFound:\n";
            cout << c.name << " | " << c.phone << " | " << c.email << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNot Found!\n";
}

// ---------- DELETE ----------
void ContactBook::deleteContact() {
    string key;
    cout << "Enter phone: ";
    cin >> key;

    for (auto it = contacts.begin(); it != contacts.end(); it++) {
        if (it->phone == key) {
            contacts.erase(it);
            save();
            cout << "\nDeleted Successfully!\n";
            return;
        }
    }

    cout << "\nNot Found!\n";
}

// ---------- EDIT ----------
void ContactBook::editContact() {
    string key;
    cout << "Enter phone: ";
    cin >> key;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (auto &c : contacts) {
        if (c.phone == key) {
            cout << "Enter new details:\n";

            cout << "Name: ";
            getline(cin, c.name);

            cout << "Phone: ";
            getline(cin, c.phone);

            cout << "Email: ";
            getline(cin, c.email);

            save();
            cout << "\nUpdated!\n";
            return;
        }
    }

    cout << "\nNot Found!\n";
}