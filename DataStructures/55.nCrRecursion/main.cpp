#include <iostream>
using namespace std;


int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return factorial(n-1) * n;
}


int nCr(int n, int r){
    int fN, fR, fNR;
    fN = factorial(n);
    fR = factorial(r);
    fNR = factorial(n-r);
    return fN / (fR * fNR);
}


int nCrPascal(int n, int r){
    if (r == 0 || r == n){
        return 1;
    }
    return nCrPascal(n-1, r-1) + nCrPascal(n-1, r);
}

int main() {

    cout << factorial(4) << endl;
    cout << nCr(3, 1) << endl;
    cout << nCrPascal(5, 3) << endl;

    return 0;
}