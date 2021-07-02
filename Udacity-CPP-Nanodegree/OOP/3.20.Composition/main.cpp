#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

/*
 * Composition is close alternative to inheritance. Composition involves constructing or composing
 * classes from other classes instead of inheriting traits from a parent class.
 *
 * A common way to distinguish "composition" from "inheritance" is to think about what an object
 * can do, rather that what it is -> "Has a" versus "Is a", e.g. Composition: Cat "has a" head
 * versus Inheritance: Cat "is a" mammal.
 *
 * If a class needs to only extend a small amount of functionality offered by another class then
 * it makes sense to INHERIT from that other class.
 *
 * If a class needs to contain functionality from a variety of otherwise unrelated classes, it makes
 * sense to compose class from those other classes.
 */

// Define pi
#define PI 3.14159


 // TODO: Compose Circle from LineSegment instead of inheriting Circle from LineSegment

 // Define Line Segment class
 class LineSegment {
 public:
     double length;
 };


 class Circle {
 private:
    LineSegment& radius;

 public:
     Circle(LineSegment& radius) : radius(radius){};
     double getArea();
 };

 double Circle::getArea() {
     return PI * pow(radius.length, 2);
 }


int main() {

    LineSegment radius {3.0};
    Circle circle(radius);
    assert(int(circle.getArea()) == 28.0);

    cout << "Area of circle: " << circle.getArea() << endl;

    return 0;
}