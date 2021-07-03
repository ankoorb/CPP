#include <iostream>

using namespace std;

int main() {

    int* ptr = new int;
    *ptr = 7;

    cout << "Value at ptr (address)                 : " << ptr << endl;
    cout << "Value at *ptr (dereferencing pointer)  : " << *ptr << endl;

    delete ptr;

    return 0;
}