#include <iostream>
#include <vector>
using namespace std;

struct Item {
    string name;
    double price;
};

int main() {
    vector<Item> menu = {{"Pizza",10},{"Burger",7},{"Cola",3}};
    vector<Item> order;
    int choice;

    do {
        cout << "\n1.Menu\n2.Add\n3.Bill\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice==1)
            for (int i=0;i<menu.size();i++)
                cout<<i<<" "<<menu[i].name<<" $"<<menu[i].price<<endl;

        else if (choice==2) {
            int i; cin>>i;
            if (i>=0 && i<menu.size()) order.push_back(menu[i]);
        }

        else if (choice==3) {
            double total=0;
            for (auto &i:order) total+=i.price;
            cout<<"Total: $"<<total<<endl;
        }

    } while(choice!=0);
}
