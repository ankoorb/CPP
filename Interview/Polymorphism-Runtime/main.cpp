#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Base {
public:
    virtual void Display() const { cout << "Base class object" << endl; }
};

class Derived : public Base {
public:
    void Display() const override { cout << "Derived class object" << endl; }
};

void Display(const Base& obj){
    obj.Display();
}


int main() {

    // Static or Compile time polymorphism
    Base b;
    b.Display();

    Derived d;
    d.Display();

    cout << endl;

    // Dynamic or Run time polymorphism
    Display(d);

    Base* base_ptr = new Derived();
    base_ptr->Display();

    unique_ptr<Base> ptr = make_unique<Derived>();
    ptr->Display();

    cout << endl;

    unique_ptr<Base> a_ptr = make_unique<Base>();
    unique_ptr<Base> b_ptr = make_unique<Derived>();
    unique_ptr<Base> c_ptr = make_unique<Base>();
    unique_ptr<Base> d_ptr = make_unique<Derived>();

    vector<unique_ptr<Base>> ptrs;
    ptrs.emplace_back(move(a_ptr));
    ptrs.emplace_back(move(b_ptr));
    ptrs.emplace_back(move(c_ptr));
    ptrs.emplace_back(move(d_ptr));

    for (const auto& ptr: ptrs){
        ptr->Display();
    }
    cout << endl;

    // Base class reference
    Derived derived;
    Base& base_ref = derived;
    derived.Display();
    cout << endl;

    vector<Base> refs;
    refs.emplace_back(Derived());
    refs.emplace_back(Base());
    refs.emplace_back(Derived());
    refs.emplace_back(Base());

    for (const auto& ref: refs){
        ref.Display();
    }

    return 0;
}