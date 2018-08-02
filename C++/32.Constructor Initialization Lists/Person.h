//
// Created by Ankoor Bhagat on 5/30/18.
//

#ifndef INC_32_CONSTRUCTOR_INITIALIZATION_LISTS_PERSON_H
#define INC_32_CONSTRUCTOR_INITIALIZATION_LISTS_PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(): name(""), age(0) {};  // Default construstor
    Person(string name, int age);  // Parameterized constructor

    string toString();
};


#endif //INC_32_CONSTRUCTOR_INITIALIZATION_LISTS_PERSON_H
