//
// Created by Ankoor Bhagat on 11/30/17.
//

#ifndef INC_30_OVERLOADING_CONSTRUCTORS_PERSON_H
#define INC_30_OVERLOADING_CONSTRUCTORS_PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor without parameter
    Person();

    // Constructor with parameter - Defined inline here instead of Person.cpp
    Person(string new_name) { name = new_name; age = 0;};

    // Constructor with parameters - Defined in Person.cpp
    Person(string new_name, int new_age);

    // Methods
    string toString();

};


#endif //INC_30_OVERLOADING_CONSTRUCTORS_PERSON_H
