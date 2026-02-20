#include <iostream>
using namespace std;

class Arena{
    char buffer[1024];
    size_t offset=0;
public:
    void* alloc(size_t sz){
        void* p = buffer + offset;
        offset += sz;
        return p;
    }
};

int main(){
    Arena a;
    int* x = (int*)a.alloc(sizeof(int));
    *x = 123;
    cout<<*x;
}
