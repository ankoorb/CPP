#include <iostream>

using namespace std;

int multiplyByTwo(int x){
    x = 2 * x;
    return x;
}

int multiplyByTwoRef(int& x){
    x = 2 * x;
    return x;
}

int main() {

    int y = 5;
    cout << "y = " << y << endl;

    int z = multiplyByTwo(y);
    cout << "z = " << z << endl;
    cout << "y still = " << y << endl;

    z = multiplyByTwoRef(y);
    cout << "z = " << z << endl;
    cout << "y is now = " << y << endl;

    return 0;
}

