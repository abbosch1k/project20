#include <iostream>
#include <vector>
using namespace std;

struct Room {
    int number;
    bool booked;
};

int main() {
    vector<Room> rooms = {{101,false},{102,false},{103,false}};
    int choice;

    do {
        cout << "\n1.Show\n2.Book\n3.Cancel\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            for (auto &r:rooms)
                cout << r.number << " - "
                     << (r.booked?"Booked":"Free") << endl;
        }
        else if (choice == 2) {
            int n; cin >> n;
            for (auto &r:rooms)
                if (r.number==n && !r.booked) r.booked=true;
        }
        else if (choice == 3) {
            int n; cin >> n;
            for (auto &r:rooms)
                if (r.number==n) r.booked=false;
        }

    } while (choice!=0);
}
