//
// Created by Ankoor Bhagat on 6/27/18.
//

#ifndef INC_45_NAMESPACES_ANIMAL_H
#define INC_45_NAMESPACES_ANIMAL_H

#include <iostream>
using namespace std;

namespace canine {

    const string NAME = "Goofy";

    class Dog {
    public:
        Dog();
        virtual ~Dog();
        void speak();
    };
}


#endif //INC_45_NAMESPACES_ANIMAL_H
