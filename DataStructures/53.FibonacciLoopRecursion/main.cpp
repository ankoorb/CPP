#include <iostream>
using namespace std;

int fib(int n){
    if (n <= 1){
        return n;
    }
    return fib(n-2) + fib(n-1);
}

int iFib(int n){
    if (n <= 1){
        return n;
    }

    int prevPrev = 0;
    int prev = 1;
    int r;

    for (int i=2; i<=n; i++){
        r = prevPrev + prev;
        prevPrev = prev;
        prev = r;
    }
    return r;
}

int F[10];

int mFib(int n){

    if (n <= 1){
        F[n] = n;
        return n;
    } else {
        if (F[n-2] == -1){
            F[n-2] = fib(n-2);
        }
        if (F[n-1] == -1){
            F[n-1] = fib(n-1);
        }
        return F[n-2] + F[n-1];
    }

}
int main() {

    for (int i=0; i<10; i++){
        F[i] = -1;
    }

    cout << fib(7) << endl;
    cout << iFib(7) << endl;
    cout << mFib(7) << endl;

    return 0;
}