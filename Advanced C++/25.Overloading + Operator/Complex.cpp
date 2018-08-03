//
// Created by Ankoor Bhagat on 7/29/18.
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

    Complex operator+(const Complex &c1, const Complex &c2){
        return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
    }

    Complex operator+(const Complex &c1, double d){
        return Complex(c1.getReal() + d, c1.getImaginary());
    }

    Complex operator+(double d, const Complex &c1){
        return Complex(d + c1.getReal(), c1.getImaginary());
    }

}