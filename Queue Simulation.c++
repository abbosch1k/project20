#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q;
    int choice;

    do{
        cout<<"\n1.Add Customer\n2.Serve\n3.Show\n0.Exit\nChoice: ";
        cin>>choice;

        if(choice==1){
            string name;
            cin>>name;
            q.push(name);
        }
        else if(choice==2 && !q.empty()){
            cout<<"Serving "<<q.front()<<endl;
            q.pop();
        }
        else if(choice==3){
            queue<string> temp=q;
            while(!temp.empty()){
                cout<<temp.front()<<endl;
                temp.pop();
            }
        }

    }while(choice!=0);
}
