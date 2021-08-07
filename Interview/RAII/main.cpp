#include <iostream>
using namespace std;

/*
 * New object: Allocate memory
 * Remove object: free memory
 * Object own their data
 *
 * Whenever you create an object it should own its resources, whenever the object
 * is removed it should free its resources
 */

class Demo {
public:
    int* data_;
    Demo() { data_ = new int[5]; }
    ~Demo() {
        delete[] data_;
        data_ = nullptr;
    }
};

int main() {

    Demo a;
    // Demo b(a);
    // b.data_ pointing at a.data_ i.e. 2 objects pointing at same memory allocated by a
    // Need to implement copy constructor, assighment operator, move constructor and move operator

    // Shallow and Deep copy problem
    // Shallow copy: Just copy pointers and not data
    // Deep copy: create new pointers and copy data
    // Default copy constructor and assignment operator implement shallow copy

    // RAII + shallow copy: Dangling pointer
    // RAII + Rule of All Or Nothing: correct
    // Use smart pointers

    return 0;
}