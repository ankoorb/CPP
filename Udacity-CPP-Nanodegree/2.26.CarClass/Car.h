//
// Created by Ankoor Bhagat on 6/29/21.
//

#ifndef INC_2_26_CARCLASS_CAR_H
#define INC_2_26_CARCLASS_CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string color;
    int number;
    int distance = 0;

    Car(string c, int n): color(c), number(n) {};

    void printCarData();
    void incrementDistance();
};


#endif //INC_2_26_CARCLASS_CAR_H
