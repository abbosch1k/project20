#include <iostream>
#include <atomic>
using namespace std;

int main(){
    atomic_flag flag = ATOMIC_FLAG_INIT;

    if(!flag.test_and_set())
        cout<<"First set\n";

    flag.clear();
}
