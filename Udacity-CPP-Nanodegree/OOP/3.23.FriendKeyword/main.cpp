#include <iostream>
#include <cassert>

using namespace std;

/*
 * Friend classes provide an alternative inheritance mechanism to derived classes. Friend class
 * can access private members of the base class. In classical inheritance a derived class can only
 * access public and protected members of the base class.
 */

// Declare class Rectangle
class Rectangle;

// Define class Square
class Square {

private:
    int side;
    // Add friend class Rectangle
    friend class Rectangle;

public:
    Square(int s) : side(s) {};
};

// Define class Rectangle
class Rectangle {

private:
    int width;
    int height;

public:
    Rectangle(const Square& s);
    int getArea() const ;
};

// Define a Rectangle constructor that takes a square
Rectangle::Rectangle(const Square &s) : width(s.side), height(s.side) {}

// Define getArea to compute area of Rectangle
int Rectangle::getArea() const {
    return width * height;
}

int main() {

    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.getArea() == 16);

    return 0;
}