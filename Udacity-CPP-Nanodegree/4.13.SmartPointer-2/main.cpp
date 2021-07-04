#include <iostream>
#include <memory>

using namespace std;

class Class {
public:
    void classMethod() { cout << "Class::classMethod()" << endl;}
};

int main() {

    shared_ptr<Class> ptr_1 (new Class);
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;
    cout << endl;

    shared_ptr<Class> ptr_2(ptr_1);
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;
    cout << endl;

    shared_ptr<Class> ptr_3(ptr_2);
    cout << "Memory address of ptr_1: " << ptr_1.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;
    cout << endl;

    cout << "Use count of ptr_1: " << ptr_1.use_count() << endl;
    cout << "Use count of ptr_2: " << ptr_2.use_count() << endl;
    cout << "Use count of ptr_3: " << ptr_3.use_count() << endl;
    cout << endl;

    ptr_1.reset();
    cout << "Memory address of ptr_1 after reset: " << ptr_1.get() << endl;
    cout << "Memory address of ptr_2: " << ptr_2.get() << endl;
    cout << "Use count of ptr_2: " << ptr_2.use_count() << endl;
    cout << endl;

    ptr_2.reset();
    cout << "Memory address of ptr_2 after reset: " << ptr_2.get() << endl;
    cout << "Memory address of ptr_3: " << ptr_3.get() << endl;
    cout << "Use count of ptr_3: " << ptr_3.use_count() << endl;
    cout << endl;

    return 0;
}