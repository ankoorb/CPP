#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    string color {"white"};
    Vehicle(){ cout << "Default constructor of Vehicle class" << endl; }
    Vehicle(string color){
        this->color = color;
        cout << "Parameterized constructor of Vehicle class" << endl;
    }
};

class Car : public Vehicle {
public:
    int n_wheels;
    Car() { cout << "Default constructor of Car class" << endl; }
    Car(int wheels) {
        this->n_wheels = wheels;
        cout << "Parameterized constructor of Car class" << endl;
    }

    // Passing parameter to Vehicle class
    Car(string color, int wheels) : Vehicle(color) {
        this->n_wheels = wheels;
        cout << "Parameterized constructor of Car class" << endl;
    }
};

int main() {

    Car honda;  // Default constructor of Car class
    cout << endl;

    Car toyota(4); // Parameterized constructor of Car class
    cout << endl;

    Car ferrari("Red", 4); // Passing parameter to Vehicle class

    return 0;
}