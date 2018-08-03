//
// Created by Ankoor Bhagat on 7/27/18.
//

#ifndef INC_24_A_COMPLEX_NUMBER_CLASS_COMPLEX_H
#define INC_24_A_COMPLEX_NUMBER_CLASS_COMPLEX_H

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
        Complex(const Complex &other);

        // Overriding assignment operator
        const Complex &operator=(const Complex &other);

        // Get methods
        double getReal() const;
        double getImaginary() const;
    };

    // Return type is ostream reference
    ostream &operator<<(ostream &out, const Complex &c);

}


#endif //INC_24_A_COMPLEX_NUMBER_CLASS_COMPLEX_H
