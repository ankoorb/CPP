#include <iostream>
using namespace std;

double e(int x, int n){

    static double r = 1;

    cout << "x: " << x << ", n: " << n << ", r: " << r << endl;

    if (n == 0){
        return r;
    }

    r = 1 + ((double)x/n) * r;



    return e(x, n-1);

}

int main() {

    cout << e(1, 10) << endl;

    return 0;
}