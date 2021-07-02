#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

class Sphere {
private:
    static float const PI;
    int radius;
    float volume;
    void validate();

public:
    Sphere(int radius);

    int getRadius() const;
    float getVolume() const;

    void setRadius(int radius);
};

float const Sphere::PI {3.14159f};

class Circle {
private:
    static float constexpr PI {3.14159f};  // Initializing a constant with static within class use constexpr
    int radius;
public:
    Circle(int radius) : radius(radius) {}
    float getArea() {
        return PI * (float)(pow(radius, 1));
    }
};


// Static variables must be defined in header and initialized outside class and within the global scope
class Foo {
public:
    static int count;
    Foo(){ Foo::count++; }
};

int Foo::count{0};  // Initializing Foo::count

int main() {

    Sphere sphere(7);

    assert(sphere.getRadius() == 7);
    assert(abs(sphere.getVolume() - 1436.75) < 1);

    bool caught {false};
    try {
        sphere.setRadius(-10);
    } catch (...){
        caught = true;
    }
    assert(caught);

    Foo foo1;
    Foo foo2;
    Foo foo3;
    cout << "Number of times foo object is created: " << Foo::count << endl;

    Circle circle(5);
    cout << "Area of circle is: " << circle.getArea() << endl;

    return 0;
}


Sphere::Sphere(int radius) {
    setRadius(radius);
    volume = (4.0f / 3.0f) * PI * (float)(pow(getRadius(), 3));
}

int Sphere::getRadius() const {
    return radius;
}

float Sphere::getVolume() const {
    return volume;
}

void Sphere::setRadius(int radius) {
    this->radius = radius;
    validate();
}

void Sphere::validate() {
    if (radius <= 0){
        throw invalid_argument("Radius must be greater than 0");
    }
}