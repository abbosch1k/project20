#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    bool available;

    Book(string t) : title(t), available(true) {}
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n1.Add Book\n2.Show Books\n3.Borrow\n4.Return\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string title;
            cout << "Title: ";
            cin >> title;
            library.push_back(Book(title));
        }
        else if (choice == 2) {
            for (int i = 0; i < library.size(); i++)
                cout << i << ". "
                     << library[i].title
                     << " | "
                     << (library[i].available ? "Available" : "Borrowed")
                     << endl;
        }
        else if (choice == 3) {
            int i;
            cin >> i;
            if (i >= 0 && i < library.size() && library[i].available)
                library[i].available = false;
        }
        else if (choice == 4) {
            int i;
            cin >> i;
            if (i >= 0 && i < library.size())
                library[i].available = true;
        }

    } while (choice != 0);
}
