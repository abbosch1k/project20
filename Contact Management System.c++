#include <iostream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\n1.Add\n2.Show\n3.Search\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Contact c;
            cin >> c.name >> c.phone;
            contacts.push_back(c);
        }
        else if (choice == 2) {
            for (auto &c : contacts)
                cout << c.name << " - " << c.phone << endl;
        }
        else if (choice == 3) {
            string name;
            cin >> name;
            for (auto &c : contacts)
                if (c.name == name)
                    cout << c.phone << endl;
        }

    } while (choice != 0);
}
