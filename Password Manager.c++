#include <iostream>
#include <vector>
using namespace std;

class Credential {
public:
    string site;
    string password;

    Credential(string s, string p)
        : site(s), password(p) {}
};

int main() {
    vector<Credential> vault;
    int choice;

    do {
        cout << "\n1.Add\n2.Show\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string site, pass;
            cout << "Site: ";
            cin >> site;
            cout << "Password: ";
            cin >> pass;
            vault.push_back(Credential(site, pass));
        }
        else if (choice == 2) {
            for (auto &c : vault)
                cout << c.site
                     << " -> "
                     << c.password << endl;
        }

    } while (choice != 0);
}
