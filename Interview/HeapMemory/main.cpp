#include <iostream>
using namespace std;

int main() {

    int size = 2;
    int* ptr = nullptr;
    {
        ptr = new int[size];
        ptr[0] = 7;
        ptr[1] = 15;
    }

    cout << "Before: delete" << endl;
    for (auto i = 0; i < size; i++){
        cout << ptr[i] << endl;
    }

    // Free heap memory
    delete[] ptr;
    ptr = nullptr;

    // Memory Leak
    int* ptr_a = new int(0);
    int* ptr_b = new int(1);
    cout << ptr_a << " " << ptr_b << endl;
    cout << *ptr_a << " " << *ptr_b << endl;
    ptr_b = ptr_a; // ptr_b is overwritten so no chance to access memory
    cout << ptr_a << " " << ptr_b << endl;
    cout << *ptr_a << " Memory leak + Dangling Pointer" << *ptr_b << endl;
    delete ptr_a;
    ptr_a = nullptr;
    //delete ptr_b; // Error
    cout << ptr_b << " " << *ptr_b << endl;

    return 0;
}
