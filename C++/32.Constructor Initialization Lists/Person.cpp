//
// Created by Ankoor Bhagat on 5/30/18.
//

#include "Person.h"
#include "sstream"

//Person::Person() {
//    age = 0;
//    name = "";
//}

//Person::Person(): name(""), age(0) {}

//Person::Person(string name, int age) {
//    this->name = name;
//    this->age = age;
//}

Person::Person(string name, int age): name(name), age(age) {

}

string Person::toString() {
    stringstream ss;
    ss << "Name: " << name << "; Age: " << age;
    return ss.str();
}