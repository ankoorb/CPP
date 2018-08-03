#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading + operator

int main() {

    Complex c(7, 15);

    cout << *c << endl;

    cout << *c + c << endl;

//    cout << *c +  *Complex(9, 3) << endl;

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
 *  Overloading == and != comparison operators
 *
 *  Overloading * operator (i.e dereferencing operator)
 *
 *  Complex conjugate -> It is the same number but the sign on imaginary part is flipped, denoted
 *  by c* (similar to dereference operator, except it is on the wrong side)
 *
 *  Only thing to watch out for is operator precedence
 *
 *  Exercise: Implement some operator that you thing not implemented
 *
 */