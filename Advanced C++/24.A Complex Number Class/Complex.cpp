//
// Created by Ankoor Bhagat on 7/27/18.
//

#include "Complex.h"

namespace complex {

    Complex::Complex(): real(0), imaginary(0){}
    Complex::~Complex() {}

    Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary) {}

    Complex::Complex(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;
    }

    // Return type is const Complex reference
    const Complex &Complex::operator=(const Complex &other){
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    double Complex::getReal() const { return real; }
    double Complex::getImaginary() const { return imaginary; }

    ostream &operator<<(ostream &out, const Complex &c){
        cout << "(" << c.getReal() << ", " << c.getImaginary() << ")";
        return out;
    }

}