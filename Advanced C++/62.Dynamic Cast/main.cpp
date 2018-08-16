#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak(){ cout << "Parent" << endl; }
};

class Son: public Parent {

};

class Daughter: public Parent {

};

int main() {

    Parent parent;
    Son son;

//    If you have a pointer of a parent class type to a child class type, you might later
//    * on want to have a pointer to the child class type and you might want to cast the
//    * pointer of the parent class type back to the child class type.
    Parent *pps = &parent;
    //Son *pss = static_cast<Son *>(pps);  // Unsafe
    Son *pss = dynamic_cast<Son *>(pps);

    if(pss == nullptr){
        cout << "Invalid cast" << endl;
    } else {
        cout << pss << endl;
    }

    return 0;
}

/*
 * If you have a pointer of a parent class type to a child class type, you might later
 * on want to have a pointer to the child class type and you might want to cast the
 * pointer of the parent class type back to the child class type.
 *
 * `dynamic_cast` checks types at runtime to make sure you are doing something that
 * makes sense. It is better to use `dynamic_cast` instead of `static_cast` because
 * `static_cast` does not do runtime checking
 *
 * `error: 'Parent' is not polymorphic` - Make Parents method `virtual`
 */

