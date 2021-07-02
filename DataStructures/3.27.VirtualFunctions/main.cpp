#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// Virtual functions are declared in a base class and can be overridden by derived class
// Appending "= 0" to end of function declaration makes the function "pure" virtual functions
// A "pure" virtual function is a virtual function that the base class declares but not define
// A pure virtual function make a base class abstract, i.e. the base class can not be instantiated

// TODO: Define pi
#define PI 3.141529

// TODO: Define the abstract class Shape
// TODO: Define public virtual functions Area() and Perimeter()
// TODO: Append the declarations with = 0 to specify pure virtual functions

class Shape {
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};


// TODO: Define Rectangle to inherit publicly from Shape
// TODO: Declare public constructor
// TODO: Override virtual base class functions Area() and Perimeter()
// TODO: Declare private attributes width and height

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    double Area() const override;
    double Perimeter() const override;
};


// TODO: Define Circle to inherit from Shape
// TODO: Declare public constructor
// TODO: Override virtual base class functions Area() and Perimeter()
// TODO: Declare private member variable radius

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    double Area() const override;
    double Perimeter() const override;
};


int main() {

    double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);

    return 0;
}


Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::Area() const { return width * height; }

double Rectangle::Perimeter() const { return 2 * (width + height); }

Circle::Circle(double r) : radius(r) {}

double Circle::Area() const { return PI * pow(radius, 2); }

double Circle::Perimeter() const { return 2 * PI * radius; }
