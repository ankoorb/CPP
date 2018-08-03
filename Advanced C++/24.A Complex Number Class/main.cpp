#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading = operator

int main() {

    Complex c1(2, 3);

    Complex c2(c1);  // Using copy constructor

    Complex c3;

    c3 = c2;  // Using assignment operator

    cout << c2 << ": " << c3 << endl;

    return 0;
}