//
// Created by Ankoor Bhagat on 11/28/17.
//

#ifndef INC_28_GETTERS_AND_SETTERS_PERSON_H
#define INC_28_GETTERS_AND_SETTERS_PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
    string name;

public:
    // Constructor
    Person();

    // Methods
    string toString();
    void set_name(string new_name);
    string get_name();

};


#endif //INC_28_GETTERS_AND_SETTERS_PERSON_H
