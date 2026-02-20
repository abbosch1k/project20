#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Expense {
    string category;
    double amount;
};

int main() {
    vector<Expense> expenses;
    int choice;

    do {
        cout << "\n1.Add\n2.Show\n3.Total\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;
            cout << "Category: ";
            cin >> e.category;
            cout << "Amount: ";
            cin >> e.amount;
            expenses.push_back(e);
        }
        else if (choice == 2) {
            for (auto &e : expenses)
                cout << e.category << " - $" << e.amount << endl;
        }
        else if (choice == 3) {
            double total = 0;
            for (auto &e : expenses) total += e.amount;
            cout << "Total: $" << total << endl;
        }

    } while (choice != 0);
}
