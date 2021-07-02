#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    int n_wheels {0};
    string color {"Blue"};
    string make {"Generic"};

    void Print() const {
        cout << "This " << color << " " << make << " vehicle has " << n_wheels << " wheels" << endl;
    }
};


class Car : public Vehicle {
public:
    bool sunroof {false};
};

class Bicycle : public Vehicle {
public:
    bool kickstand {false};
};


int main() {

    Car car;
    car.Print();

    Bicycle bicycle;
    bicycle.Print();

    return 0;
}