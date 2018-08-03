#include <iostream>
using namespace std;

class Parent {
private:
    int u;
public:
    virtual void print(){ cout << "Parent" << endl; }

    Parent(): u(0) {};

    Parent(const Parent &other): u(0) {
        u = other.u;
        cout << "Copy Constructor: Parent" << endl;
    };
};

class Child: public Parent {
private:
    int v;
public:
    // u is private variable so its scope is limited to class where it is defined
    //Child(): u(0){};
    Child(): v(0){};
    void print(){ cout << "Child" << endl; }
};

int main() {

    Parent p = Child();  // Invoking implicit copy constructor when copy constructor not implemented
    p.print();

    return 0;
}


/*
 * If we make print method virtual in Parent class the output is "Child"
 *
 * Since the method in Parent class is not virtual, there is no lookup mechanism for
 * C++ to find the right method to call
 *
 * Copy Constructor implemented in Parent class with no default constructor. Error is
 * caused when Child class inherits from Parent class because when we create a sub-class,
 * sub-classes have to run constructor of the parent classes in order to be instantiated.
 * So when we define a sub-class we must either have a default constructor in the parent
 * class or we must specify what constructor we want to run in the parent class.
 *
 * Parent p2 = Child() -> Parent(const Parent &other) -> Why this works? You have reference
 * to a Parent class, you can assign an object of subclass of the parent class to it. This
 * gives rise to object slicing.
 *
 * Add a private variable to parent. Parent Copy constructor can not copy "two" variable in
 * in Child, so "two" gets thrown away
 *
 */

/*
 * Parent &p1 = c1; Reference to a parent class referring to any object of sub-class
 *
 *
 */