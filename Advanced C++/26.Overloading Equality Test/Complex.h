//
// Created by Ankoor Bhagat on 7/29/18.
//

#ifndef INC_26_OVERLOADING_EQUALITY_TEST_COMPLEX_H
#define INC_26_OVERLOADING_EQUALITY_TEST_COMPLEX_H


#include <iostream>
using namespace std;
namespace complex {

    class Complex {
    private:
        double real;
        double imaginary;
    public:
        Complex();
        virtual ~Complex();

        // Constructor with params
        Complex(double real, double imaginary);

        // Copy Constructor
        Complex(const Complex &other);  // Do not leave const

        // Overriding assignment operator
        const Complex &operator=(const Complex &other);  // Return type is const Complex reference

        // Get methods
        double getReal() const;
        double getImaginary() const;

        // Equals test
        bool operator==(const Complex &other) const;

        // Not equals test
        bool operator!=(const Complex &other) const;

    };

    // Return type is ostream reference
    ostream &operator<<(ostream &out, const Complex &c);

    // Return type for + operator is Complex object
    Complex operator+(const Complex &c1, const Complex &c2);  // Reference for efficiency

    // Adding real value to real number of complex number
    Complex operator+(const Complex &c1, double d);

    // When double on left and Complex on the right side
    Complex operator+(double d, const Complex &c1);


}



#endif //INC_26_OVERLOADING_EQUALITY_TEST_COMPLEX_H
