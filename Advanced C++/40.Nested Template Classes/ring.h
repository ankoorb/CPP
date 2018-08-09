//
// Created by Ankoor Bhagat on 8/2/18.
//

#ifndef INC_40_NESTED_TEMPLATE_CLASSES_RING_H
#define INC_40_NESTED_TEMPLATE_CLASSES_RING_H

#include <iostream>
using namespace std;

template <class T>
class ring {
public:
    class iterator;  // Just need this here
};



// inner iterator class separated out from outer ring class
template <class T>
class ring<T>::iterator {  // We do not want iterator to have its own template
public:
    void print(){ cout << "Hello from iterator!"  << T() << endl; }
};



#endif //INC_40_NESTED_TEMPLATE_CLASSES_RING_H


// C++ allows to declare nested classes

//#include <iostream>
//using namespace std;
//
//class ring {
//public:
//    class iterator {
//    public:
//        void print(){ cout << "Hello from iterator!" << endl; }
//    };
//};


//#include <iostream>
//using namespace std;
//
//class ring {
//public:
//    class iterator;  // Just need this here
//};
//
//class ring::iterator {
//public:
//    void print();
//
//void ring::iterator::print() { cout << "Hello from iterator!" << endl; }