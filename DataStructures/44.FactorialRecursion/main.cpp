#include <iostream>
using namespace std;

int factorial(int n){
    if (n <= 0){
        return 1;
    } else {
        return factorial(n-1) * n;
    }
}

int iFactorial(int n){
    int f = 1;
    if (n <= 0){
        return f;
    }
    for (int i=1; i<=n; i++){
        f *= i;
    }
    return f;
}

int main() {

    cout << factorial(-1) << endl;
    cout << factorial(0) << endl;
    cout << factorial(3) << endl;
    cout << factorial(4) << endl;
    cout << factorial(10) << endl;

    cout << iFactorial(-1) << endl;
    cout << iFactorial(0) << endl;
    cout << iFactorial(3) << endl;
    cout << iFactorial(4) << endl;
    cout << iFactorial(10) << endl;

    return 0;
}