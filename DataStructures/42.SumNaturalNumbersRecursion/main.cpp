#include <iostream>
using namespace std;

int sum(int n){
    if (n == 0) {
        return 0;
    }
    return sum(n-1) + n;
}

int Fsum(int n){
    return n * (n+1)/2;
}

int Isum(int n){
    int s = 0;
    for (int i=1; i<=n; i++){
        s += i;
    }
    return s;
}


int main() {

    cout << sum(5) << endl;
    cout << Fsum(5) << endl;
    cout << Isum(5) << endl;

    return 0;
}