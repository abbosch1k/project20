#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> database;
    int choice;

    do {
        cout << "\n1.Insert\n2.Find\n3.Delete\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string key, value;
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            database[key] = value;
        }
        else if (choice == 2) {
            string key;
            cin >> key;
            if (database.count(key))
                cout << database[key] << endl;
            else
                cout << "Not found\n";
        }
        else if (choice == 3) {
            string key;
            cin >> key;
            database.erase(key);
        }

    } while (choice != 0);
}
