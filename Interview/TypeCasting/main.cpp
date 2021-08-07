#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
public:
    virtual void Print() const = 0;
    void Area() { cout << "Shape Area" << endl; }
};

class Square : public Shape {
public:
    void Print() const override { cout << "Square" << endl; }
};

int main() {

    // 3 ways of type casting:
    // (1) static_cast: Convert type of a variable at compile time
    //     Pointer to an object of Derived class can be upcast to a
    //     pointer of a Base class. Both classes should be related
    //     static_cast<NewType>(variable)
    // (2) reinterpret_cast: Reinterpret bytes of a variable as another
    //     type, mostly used in writing binary data. It does not convert
    //     the value rather it will take those bits and show it as of another
    //     type, e.g. float will be shown as int
    // (3) dynamic_cast: Convert a pointer to a variable of Derived type to a
    //     pointer of a Base type. Conversion happens at runtime. If derived_ptr
    //     can not be converted to Base*, a nullptr is returned (i.e. when classes
    //     are not related)
    //     dynamic_cast<Base*>(derived_ptr)


    // Upcasting: From Derived class to Base class
    // Downcasting: From Base class to Derived class

    unique_ptr<Shape> shape_ptr = make_unique<Square>();
    shape_ptr->Print();
    shape_ptr->Area();


    return 0;
}