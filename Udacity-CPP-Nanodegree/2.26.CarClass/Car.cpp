//
// Created by Ankoor Bhagat on 6/29/21.
//

#include "Car.h"

void Car::printCarData() {
    cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << endl;
}

void Car::incrementDistance() {
    distance++;
}