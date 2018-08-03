#include <iostream>
#include "complex.h"
using namespace std;
using namespace complex;

// Overloading + operator

int main() {

    Complex c1(3, 4);
    Complex c2(3, 4);
    Complex c3(2, 7);

    if(c1 == c2){
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }

    if(c2 != c3){
        cout << "Not Equal" << endl;
    }
    else {
        cout << "Equal" << endl;
    }




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
 *
 *
 */