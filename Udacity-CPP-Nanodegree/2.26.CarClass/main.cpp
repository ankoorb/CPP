#include <iostream>
#include <string>
#include <vector>
#include "Car.h"

using namespace std;

int main(){

    Car car1("green", 1);
    Car car2("red", 2);
    Car car3("blue", 3);

    car1.incrementDistance();

    car1.printCarData();
    car2.printCarData();
    car3.printCarData();

    vector<Car*> cars;

    Car* pc = nullptr;

    vector<string> colors = {"red", "blue", "green"};

    for (auto i=0; i<100; i++){
        pc = new Car(colors[i % 3], i + 1);
        cars.emplace_back(pc);
    }

    for (Car* c: cars){
        c->incrementDistance();
    }

    for (Car* c: cars){
        c->printCarData();
    }

    return 0;
}