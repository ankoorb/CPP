#include <iostream>

using namespace std;

// Multi-level Inheritance
class A {
public:
    void display() { cout << "Class A content" << endl; }
};

class B : public A {

};

class C : public B {

};

// Ambiguity in Multiple Inheritance
class X {
public:
    void display() { cout << "Class X content" << endl; }
};

class Y {
public:
    void display() { cout << "Class Y content" << endl; }
};

class Z : public X, public Y {

};





int main() {

    // Multi-level Inheritance
    C c_object;
    c_object.display();
    cout << endl;

    // Ambiguity in Multiple Inheritance
    Z z_object;
    // z_object.display(); // display() from X or display() from Y?
    z_object.X::display();
    z_object.Y::display();

    return 0;
}