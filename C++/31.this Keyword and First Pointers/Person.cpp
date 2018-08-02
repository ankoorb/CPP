//
// Created by Ankoor Bhagat on 12/4/17.
//

#include "Person.h"
#include <sstream>

// Constructor
Person::Person() {
    age = 0;
    name = "";
}

// Parameterized Constructor
Person::Person(string name, int age) {
    this->name = name;
    this->age = age;

    cout << "Memory location of object: " << this << endl;

}


string Person::toString() {
    stringstream ss;
    ss << "Name: " << name << " and age: " << age;
    return ss.str();
}