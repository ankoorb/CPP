#include <iostream>
using namespace std;

double e(int x, int n){

    // Static variables
    static double p = 1;
    static double f = 1;

    // Variable for storing result
    double r;

    if (n == 0){
        return 1;
    }

    r = e(x, n-1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main() {

    cout << e(1, 100);

    return 0;
}