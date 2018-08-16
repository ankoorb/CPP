#include <iostream>
using namespace std;

class Parent {
public:
    void speak(){ cout << "Parent" << endl; }
};

class Son: public Parent {

};

class Daughter: public Parent {

};

int main() {

    Parent parent;
    Son son;

    Parent *pp = &son;  // Pointer to parent, works because of polymorphism

    //Son *ps = &parent;  // Does not work

    Son *ps = static_cast<Son *>(&parent);  // This is very unsafe
    cout << ps << endl;


    Parent *pps = &son;  // Pointer to Parent pointing as Son object
    Son *pss = &son;  // Pointer to Son pointing at Son object
    Son *pss_ = static_cast<Son *>(pps);
    cout << "pss: " << pss << endl;

    /*
     * The above is potentially very error prone because what `static_cast` does is
     * that it is purely a compile time thing so there is no runtime checking.
     */

    //Parent &&p = Parent();  // Works
    Parent &&p = static_cast<Parent &&>(parent);  // Rvalue reference to lvalue
    p.speak();



    return 0;
}

/*
 * `static_cast<type_to_cast_to>(value)` -
 */

//float value = 3.14;
//cout << (int)value << endl;  // Valid
//cout << int(value) << endl;  // Valid
//cout << static_cast<int>(value) << endl;  // Static cast