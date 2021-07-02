#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

class Sphere {
private:
    static float constexpr PI {3.14159f};

public:
    static float computeVolume(int radius);
};


int main() {

    // Static member functions can be called without creating an instance of a class
    assert(abs(Sphere::computeVolume(7) - 1436.75) < 1);

    return 0;
}

float Sphere::computeVolume(int radius) {
    return (4.0f / 3.0f) * PI * (float)(pow(radius, 3));
}

