#include <iostream>
using namespace std;

void passByValue(int value) {
    value = 15;
}

// Functions that receive a memory address need to have a pointer argument
void passByReference(int *value) {  // Pointer receives memory address
    *value = 15;
}

int main() {

    int x = 7;
    int y = 7;

    cout << "Initial x: " << x << endl;
    passByValue(x);
    cout << "After pass by value, x is " << x <<endl;

    cout << "Initial y: " << y << endl;
    passByReference(&y);
    cout << "After pass by reference with pointer, y is " << y << endl;

    return 0;
}