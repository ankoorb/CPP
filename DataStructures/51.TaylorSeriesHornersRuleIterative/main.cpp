#include <iostream>
using namespace std;

double e(int x, int n){
    double r = 1;
    for (; n > 0; n--){
        r = 1 + ((double)x/n) * r;
    }
    return r;
}

double ex(int x, int n){
    double r = 1;
    double num = 1;
    double den = 1;
    for (int i=1; i<=n; i++){

        num *= x;
        den *= i;
        r += num/den;
    }
    return r;
}

int main() {

    cout << e(1, 10) << endl;
    cout << ex(1, 10) << endl;

    return 0;
}