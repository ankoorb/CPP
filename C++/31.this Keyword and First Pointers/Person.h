//
// Created by Ankoor Bhagat on 12/4/17.
//

#ifndef INC_31_THIS_KEYWORD_AND_FIRST_POINTERS_PERSON_H
#define INC_31_THIS_KEYWORD_AND_FIRST_POINTERS_PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person();

    // Parameterized constructor
    Person(string name, int age);


    string toString();
};


#endif //INC_31_THIS_KEYWORD_AND_FIRST_POINTERS_PERSON_H
