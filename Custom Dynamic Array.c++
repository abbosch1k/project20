#include <iostream>
using namespace std;

class MyVector{
    int* data;
    int size;
    int capacity;

public:
    MyVector(){
        size=0;
        capacity=2;
        data=new int[capacity];
    }

    void push_back(int val){
        if(size==capacity){
            capacity*=2;
            int* newData=new int[capacity];
            for(int i=0;i<size;i++)
                newData[i]=data[i];
            delete[] data;
            data=newData;
        }
        data[size++]=val;
    }

    void print(){
        for(int i=0;i<size;i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }

    ~MyVector(){
        delete[] data;
    }
};

int main(){
    MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.print();
}
