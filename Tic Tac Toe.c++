#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    vector<char> b(9,' ');
    for(int turn=0;turn<9;turn++){
        int move;
        if(turn%2==0){
            cin>>move;
            b[move]='X';
        } else {
            do move=rand()%9;
            while(b[move]!=' ');
            b[move]='O';
        }
        for(int i=0;i<9;i++){
            cout<<b[i];
            if((i+1)%3==0) cout<<endl;
        }
    }
}
