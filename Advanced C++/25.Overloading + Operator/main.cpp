#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading + operator

int main() {

    Complex c1(3, 4);
    cout << c1 << endl;

    Complex c2(2, 3);

    cout << c1 + c2 << endl;
    Complex c3 = c1 + c2;
    cout << c3 << endl;

    cout << c1 + c2 + c3 << endl;

    // Adding real to real value of complex
    Complex c4(3, 9);
    Complex c5 = c4 + 10;
    cout << c5 << endl;

    Complex c6(1, 1);
    cout << 6 + c6 << endl; // Error when Complex is on the right



    return 0;
}

/*
 *  Overloading + operator: (1) Make a member function; (2) Free standing function to make it
 *  more encapsulated;
 *
 *  Return type: new Complex number
 *
 *  What if we want to add a complex number to something that is not a complex, e.g. + operator
 *  that enables to add real value to the real part of the complex number.
 *
 *  Addition does not work when Complex is not on the right and other type on left side
 *
 *
 *
 */