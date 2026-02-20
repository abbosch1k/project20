#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    Product(int i, string n, int q, double p)
        : id(i), name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        int id, q;
        string name;
        double price;

        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Quantity: "; cin >> q;
        cout << "Price: "; cin >> price;

        products.push_back(Product(id, name, q, price));
        cout << "Product added.\n";
    }

    void showProducts() {
        for (auto &p : products) {
            cout << p.id << " | " << p.name
                 << " | Qty: " << p.quantity
                 << " | $" << p.price << endl;
        }
    }

    void removeProduct() {
        int id;
        cout << "Enter ID to remove: ";
        cin >> id;

        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->id == id) {
                products.erase(it);
                cout << "Removed.\n";
                return;
            }
        }
        cout << "Not found.\n";
    }

    void save() {
        ofstream out("inventory.txt");
        for (auto &p : products) {
            out << p.id << " "
                << p.name << " "
                << p.quantity << " "
                << p.price << endl;
        }
        out.close();
    }

    void load() {
        ifstream in("inventory.txt");
        int id, q;
        string name;
        double price;

        while (in >> id >> name >> q >> price) {
            products.push_back(Product(id, name, q, price));
        }
        in.close();
    }
};

int main() {
    Inventory inv;
    inv.load();

    int choice;
    do {
        cout << "\n1.Add\n2.Show\n3.Remove\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) inv.addProduct();
        else if (choice == 2) inv.showProducts();
        else if (choice == 3) inv.removeProduct();

    } while (choice != 0);

    inv.save();
}
