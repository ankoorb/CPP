#include <iostream>
using namespace std;

void descending(int n){
    if (n > 0){
        cout << n << endl;
        descending(n-1);
    }
}

void ascending(int n){
    if (n > 0){
        ascending(n-1);
        cout << n << endl;
    }
}


int main() {

    int n = 3;

    descending(n);

    ascending(n);

    return 0;
}