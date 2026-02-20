#include <iostream>
using namespace std;

class ATM {
private:
    int pin = 1234;
    double balance = 1000;

public:
    bool authenticate(int inputPin) {
        return inputPin == pin;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        cout << "Withdrawn.\n";
    }

    void showBalance() {
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    ATM atm;
    int inputPin;

    cout << "Enter PIN: ";
    cin >> inputPin;

    if (!atm.authenticate(inputPin)) {
        cout << "Wrong PIN.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n1.Deposit\n2.Withdraw\n3.Balance\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            double a;
            cin >> a;
            atm.deposit(a);
        }
        else if (choice == 2) {
            double a;
            cin >> a;
            atm.withdraw(a);
        }
        else if (choice == 3) {
            atm.showBalance();
        }

    } while (choice != 0);
}
