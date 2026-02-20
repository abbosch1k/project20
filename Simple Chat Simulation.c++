#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> messages;
    int choice;
    string msg;

    do {
        cout << "\n1.Send\n2.Show Chat\n0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            getline(cin, msg);
            messages.push_back(msg);
        }
        else if (choice == 2) {
            for (auto &m : messages)
                cout << m << endl;
        }

    } while (choice != 0);
}
