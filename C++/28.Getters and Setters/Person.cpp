//
// Created by Ankoor Bhagat on 11/28/17.
//

#include "Person.h"

// Constructor
Person::Person() {
    name = "George";
}

// Person class methods
string Person::toString() {
    return "Person's name is: " + name;
}

void Person::set_name(string new_name) {
    name = new_name;
}

string Person::get_name() {
    return name;
}