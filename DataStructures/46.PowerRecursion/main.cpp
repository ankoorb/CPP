#include <iostream>
using namespace std;

int power(int m, int n){
    if (n == 0){
        return 1;
    } else {
        return power(m, n-1) * m;
    }
}

int fPower(int m, int n){
    if (n == 0){
        return 1;
    }

    if (n % 2 == 0){
        return fPower(m * m, n/2);
    } else {
        return m * fPower(m * m, (n - 1)/2);
    }
}

int main() {

    cout << power(2, 0) << endl;
    cout << power(2, 3) << endl;
    cout << power(2, 9) << endl;

    cout << fPower(2, 9) << endl;
    cout << fPower(9, 3) << endl;

    return 0;
}