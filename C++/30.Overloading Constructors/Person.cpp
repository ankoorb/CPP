//
// Created by Ankoor Bhagat on 11/30/17.
//
#include <sstream>
#include "Person.h"

Person::Person() {
    name = "undefined";
    age = 0;
}

string Person::toString() {

    stringstream ss;
    ss << "Name: " << name << " and age: " << age;

    return ss.str();
}

Person::Person(string new_name, int new_age) {
    name = new_name;
    age = new_age;
}