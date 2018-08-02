//
// Created by Ankoor Bhagat on 7/15/18.
//

#ifndef INC_53_CREATING_STATIC_LIBRARIES_DOG_H
#define INC_53_CREATING_STATIC_LIBRARIES_DOG_H

namespace canine {

    void saySomething();

    class Dog {
    public:
        Dog();

        void speak();

        virtual ~Dog();
    };
}


#endif //INC_53_CREATING_STATIC_LIBRARIES_DOG_H
