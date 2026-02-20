#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
private:
    string username;
    string password;
    double balance;
    vector<Transaction> history;

public:
    Account(string u, string p, double b = 0) {
        username = u;
        password = p;
        balance = b;
    }

    string getUsername() const {
        return username;
    }

    bool checkPassword(string p) const {
        return p == password;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));
        cout << "Withdraw successful.\n";
    }

    bool transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return false;
        }
        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer successful.\n";
        return true;
    }

    void showHistory() const {
        cout << "\nTransaction History:\n";
        for (const auto &t : history) {
            cout << t.type << " - $" << t.amount << endl;
        }
    }

    void save(ofstream &out) {
        out << username << " "
            << password << " "
            << balance << endl;
    }
};

class BankSystem {
private:
    vector<Account> accounts;

    Account* findAccount(string username) {
        for (auto &acc : accounts) {
            if (acc.getUsername() == username)
                return &acc;
        }
        return nullptr;
    }

public:
    void loadFromFile() {
        ifstream in("bank.txt");
        string u, p;
        double b;

        while (in >> u >> p >> b) {
            accounts.push_back(Account(u, p, b));
        }
        in.close();
    }

    void saveToFile() {
        ofstream out("bank.txt");
        for (auto &acc : accounts) {
            acc.save(out);
        }
        out.close();
    }

    void registerUser() {
        string u, p;
        cout << "Enter username: ";
        cin >> u;

        if (findAccount(u)) {
            cout << "Username already exists.\n";
            return;
        }

        cout << "Enter password: ";
        cin >> p;

        accounts.push_back(Account(u, p));
        cout << "Registration successful.\n";
    }

    void login() {
        string u, p;
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        Account* acc = findAccount(u);

        if (!acc || !acc->checkPassword(p)) {
            cout << "Invalid credentials.\n";
            return;
        }

        cout << "Login successful!\n";

        int choice;
        do {
            cout << "\n1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Transfer\n";
            cout << "4. Balance\n";
            cout << "5. History\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1) {
                double amount;
                cout << "Amount: ";
                cin >> amount;
                acc->deposit(amount);
            }
            else if (choice == 2) {
                double amount;
                cout << "Amount: ";
                cin >> amount;
                acc->withdraw(amount);
            }
            else if (choice == 3) {
                string receiverName;
                double amount;
                cout << "Receiver username: ";
                cin >> receiverName;

                Account* receiver = findAccount(receiverName);
                if (!receiver) {
                    cout << "User not found.\n";
                    continue;
                }

                cout << "Amount: ";
                cin >> amount;
                acc->transfer(*receiver, amount);
            }
            else if (choice == 4) {
                cout << "Balance: $" << acc->getBalance() << endl;
            }
            else if (choice == 5) {
                acc->showHistory();
            }

        } while (choice != 0);
    }

    void menu() {
        loadFromFile();
        int choice;

        do {
            cout << "\n=== BANK SYSTEM ===\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1)
                registerUser();
            else if (choice == 2)
                login();

        } while (choice != 0);

        saveToFile();
    }
};

int main() {
    BankSystem system;
    system.menu();
    return 0;
}
