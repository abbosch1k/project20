#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string file;
    char key='K';
    cin>>file;

    fstream f(file, ios::in|ios::out|ios::binary);
    char c;
    while(f.get(c)){
        f.seekp(-1,ios::cur);
        f.put(c^key);
        f.seekg(f.tellp());
    }
}
