#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

class Sphere {
private:
    float const PI {3.14159f};
    int radius;
    float volume;
    void validate();

public:
    Sphere(int radius);

    int getRadius() const;
    float getVolume() const;

    void setRadius(int radius);
};

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