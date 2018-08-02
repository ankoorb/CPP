//
// Created by Ankoor Bhagat on 11/27/17.
//
#include <iostream>
#include "Dog.h"
using namespace std;

// Constructor
Dog::Dog() {
    cout << "Dog Created ..." << endl;
    happy = true; // Set instance variable
}

// Destructor
Dog::~Dog() {
    cout << "Dog Destroyed ..." << endl;
}

// Class Method
void Dog::speak() {
    if(happy) {
        cout << "Bark!" << endl;
    } else {
        cout << "Grr!" << endl;
    }
}