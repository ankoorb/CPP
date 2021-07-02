#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    int n_wheels {0};
    string color {"Blue"};

    void Print() const {
        cout << "This " << color << " vehicle has " << n_wheels << " wheels" << endl;
    }
};


class Car : public Vehicle {
public:
    bool sunroof {false};
};

class Bicycle : protected Vehicle {
public:
    bool kickstand {false};
};

class Scooter : private Vehicle {
public:
    bool electric {false};
    void setWheels(int w){ n_wheels = w; }
};

class ElectricScooter : public Scooter {
public:
    float charge {100.0};
};


int main() {

    Car car;
    car.n_wheels = 4;
    car.Print();

    Bicycle bicycle;
    // bicycle.Print(); // Error because of protected inheritance

    Scooter scooter;
    scooter.setWheels(2);
    // scooter.Print(); // Error because of private inheritance

    ElectricScooter escooter;
    escooter.electric = true;
    escooter.setWheels(2);

    return 0;
}