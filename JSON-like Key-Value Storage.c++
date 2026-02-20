#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,string> db;
    int choice;

    do {
        cout<<"\n1.Set\n2.Get\n0.Exit\nChoice: ";
        cin>>choice;

        if(choice==1){
            string k,v; cin>>k>>v;
            db[k]=v;
        }
        else if(choice==2){
            string k; cin>>k;
            cout<<db[k]<<endl;
        }

    }while(choice!=0);
}
