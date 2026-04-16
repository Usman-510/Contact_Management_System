#include <iostream>
#include "CONTACTBOOK.H"

using namespace std;

int main() {
    ContactBook cb;
    cb.load();

    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Contact";
        cout << "\n2. Show Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Edit Contact";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: cb.addContact(); break;
            case 2: cb.showContacts(); break;
            case 3: cb.searchContact(); break;
            case 4: cb.deleteContact(); break;
            case 5: cb.editContact(); break;
            case 0: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}