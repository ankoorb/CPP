//
// Created by Ankoor Bhagat on 6/30/18.
//

#ifndef INC_50_5_STATIC_KEYWORD_EXERCISES_DOG_H
#define INC_50_5_STATIC_KEYWORD_EXERCISES_DOG_H

#include <iostream>
using namespace std;

class Dog {
public:
    static int const PAWS = 4;
    static int id;

    static void num_paws() {
        cout << "A dog has: " << PAWS << " paws." << endl;
    }

    static int total_paws() {
        return id * PAWS;
    }

    Dog() { id = ++id; }
};


#endif //INC_50_5_STATIC_KEYWORD_EXERCISES_DOG_H
