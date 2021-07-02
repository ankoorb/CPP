#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

class Animal {
public:
    virtual string talk() const = 0; // = 0 is undefined => Pure Virtual Function
};

class Dog : public Animal {
public:
    string talk() const override { return string("Bark!"); } // Overriding Animal::talk()
};

class Cat {
public:
    string talk() const { return "Meow"; }
};

class Lion : public Cat {
public:
    string talk() const { return "Roar!"; } // Hiding Cat::talk
};

// Overriding
// TODO: Define PI

#define PI 3.1415926535

// TODO: Declare abstract class VehicleModel
// TODO: Declare virtual function Move()

class VehicleModel{
public:
    virtual void Move(double v, double phi) = 0; // Pure virtual
};


// TODO: Derive class ParticleModel from VehicleModel
// TODO: Override the Move() function
// TODO: Define x, y, and theta

class ParticleModel : public VehicleModel {
public:
    double theta {0};
    double x {0};
    double y {0};
    void Move(double v, double phi) override {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }
};


// TODO: Derive class BicycleModel from ParticleModel
// TODO: Override the Move() function
// TODO: Define L

class BicycleModel : public VehicleModel {
public:
    double theta {0};
    double x {0};
    double y {0};
    double L {1};
    void Move(double v, double phi){
        theta += v / L * tan(phi);
        x += v / L * cos(theta);
        y += v / L * sin(theta);
    }
};


int main() {

    // Animal animal; // Error: We can not instantiate object of type Animal => Animal is abstract class
    Dog dog;
    cout << dog.talk() << endl;

    Lion lion;
    cout << lion.talk() << endl;

    // Test function overriding
    ParticleModel particle;
    particle.Move(10, PI / 9);

    BicycleModel bicycle;
    bicycle.Move(10, PI / 9);

    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);

    return 0;
}