#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Base {
public:
    Base(){ cout << "Base" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived" << endl; }
};

class Shape {
    // Interface
public:
    int data = 0;
    virtual void Print() const = 0;
};

class Square : public Shape {
public:
    void Print() const override { cout << "Square" << endl; }
};

class Triangle : public Shape {
public:
    void Print() const override { cout << "Triangle" << endl; }
};

void Display(vector<char>* chars){
    for (auto c: *chars){
        cout << c << endl;
    }
    (*chars)[0] = 'z';
    (*chars).at(1) = 'x';
}

int* Largest(int* ptr_a, int* ptr_b){
    return *ptr_a > *ptr_b ? ptr_a : ptr_b;
}

vector<int>* RandVector(int size, int low, int high){
    vector<int>* output = new vector<int>(size);
    for (auto i = 0; i < size; i++){
        (*output)[i] = low + rand() % high;
    }
    return output;
}

int main() {

    int a = 4;
    int* b = &a;
    cout << a << " " << b  << " " << *b << endl;

    Derived d;
    Base* b_ptr = &d;

    Square sq;
    sq.data = 3;
    Triangle tri;
    vector<Shape*> shapes;
    shapes.emplace_back(&sq);
    shapes.emplace_back(&tri);

    for (const auto& shape: shapes){ // There is a chance the shapes will be copied that is why const reference
        shape->Print();
    }
    cout << endl;

    const Shape* const_var_ptr = &sq;
    // const_var_ptr->data = 7; // Error
    const_var_ptr = &tri;
    const_var_ptr->Print();
    cout << endl;

    Shape* const var_const_ptr = &sq;
    var_const_ptr->data = 7;
    //var_const_ptr = &tri; // Error

    const Shape* const const_var_const_ptr = &tri; // Read-only


    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    Display(&chars);
    for (auto c: chars){
        cout << c << endl;
    }

    int x = 100;
    int y = 200;
    auto z = Largest(&x, &y);
    cout << *z << endl;

    vector<int>* random = RandVector(5, 10, 20);
    for (auto v: *random){
        cout << v << endl;
    }
    delete random;

    vector<string> stooges = {"Larry", "Moe", "Curly"};
    for (auto& s: stooges){
        s = "Ankoor";
    }

    for (const auto& s: stooges){
        cout << s << " " << flush;
    }
    cout << endl;

    return 0;
}