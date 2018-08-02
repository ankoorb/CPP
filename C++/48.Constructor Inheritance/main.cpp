#include <iostream>
using namespace std;

class Machine {
private:
    int id;
public:
    Machine(): id(0) { cout << "Machine no argument constructor called." << endl; }
    Machine(int id): id(id) { cout << "Machine argument constructor called." << endl; }
    void info() { cout << "ID: " << id << endl; }
};

class Vehicle: public Machine {
public:
    Vehicle() { cout << "Vehicle no argument constructor called." << endl; }

    // Specify which constructor in the superclass to run
    Vehicle(int id): Machine(id) { cout << "Vehicle argument constructor called." << endl; }
};

class Car: public Vehicle {
public:
    Car() { cout << "Car no argument constructor called." << endl; }
    Car(int id): Vehicle(id) { cout << "Car argument constructor called." << endl; }
};

int main() {


    Car car(15);
    car.info();

    return 0;
}