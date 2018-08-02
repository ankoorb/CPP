//
// Created by Ankoor Bhagat on 11/25/17.
//
#include <iostream>
#include "Dog.h"

using namespace std;

void Dog::speak() {

    if(happy) {
        cout << "Bark!" << endl;
    } else {
        cout << "Grr!" << endl;

    }

}

void Dog::make_happy() {
    happy = true;
}

void Dog::make_sad() {
    happy = false;
}