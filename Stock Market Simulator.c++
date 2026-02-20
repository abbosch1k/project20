#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    double price=100;
    int choice, shares=0;

    do{
        price += (rand()%10 - 5);
        cout<<"Price: "<<price<<endl;
        cout<<"1.Buy 2.Sell 0.Exit: ";
        cin>>choice;

        if(choice==1){ shares++; }
        else if(choice==2 && shares>0){ shares--; }

    }while(choice!=0);

    cout<<"Shares owned: "<<shares<<endl;
}
