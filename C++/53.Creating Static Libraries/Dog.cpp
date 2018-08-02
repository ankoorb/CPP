//
// Created by Ankoor Bhagat on 7/15/18.
//

#include "Dog.h"
#include <iostream>

namespace canine {

    void saySomething(){
        std::cout << "This is a test!" << std::endl;
    }

    Dog::Dog() {};

    void Dog::speak() {
        std::cout << "Bark!" << std::endl;
    }

    Dog::~Dog() {};

}


