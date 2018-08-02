//
// Created by Ankoor Bhagat on 6/27/18.
//

#ifndef INC_45_NAMESPACES_DOG_H
#define INC_45_NAMESPACES_DOG_H

#include <iostream>
using namespace std;

namespace dog {

    const string NAME = "Pluto";

    class Dog {
    public:
        Dog();

        virtual ~Dog();

        void speak();
    };
}


#endif //INC_45_NAMESPACES_DOG_H
