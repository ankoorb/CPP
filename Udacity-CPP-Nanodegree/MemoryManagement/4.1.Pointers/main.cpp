#include <iostream>

using namespace std;

int main() {

    int val = 20;
    int* ptr = nullptr;

    ptr = &val;

    cout << "Value at ptr (address)                 : " << ptr << endl;
    cout << "address of val                         : " << &val << endl;
    cout << "Value at val (variable data)           : " << val << endl;
    cout << "Value at *ptr (dereferencing pointer)  : " << *ptr << endl;

    return 0;
}