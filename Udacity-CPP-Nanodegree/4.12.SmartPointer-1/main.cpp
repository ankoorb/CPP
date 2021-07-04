#include <iostream>
#include <memory>

using namespace std;

class Class {
public:
    void classMethod() { cout << "Class::classMethod()" << endl;}
};

int main() {

    unique_ptr<Class> ptr_1 (new Class);
    ptr_1->classMethod();
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;

    // Transfer ownership to ptr_2 using move()
    unique_ptr<Class> ptr_2 = move(ptr_1);
    ptr_2->classMethod();
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;

    unique_ptr<Class> ptr_3 = move(ptr_2);
    ptr_3->classMethod();
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;


    return 0;
}