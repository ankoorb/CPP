#include <iostream>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed " << endl; }
};

int main() {

//    {
//        shared_ptr<Test> ptest(new Test);
//        ptest->greet();
//    }

    shared_ptr<Test> ptest_(nullptr);

    {
        shared_ptr<Test> ptest = make_shared<Test>();  // Need ()

        ptest_ = ptest;  // Now memory will not get destroyed until both variables have gone out of scope
    }
    cout << "finished" << endl;  // This is run before "destroyed"

    return 0;
}

/*
 * Shared pointers are similar to unique pointers, however they do not delete the memory
 * associated with objects until all the pointers that point at that object have gone out
 * of scope. At the moment you can not use shared pointers to point at arrays, this might
 * change in C++ 17
 *
 * `shared_ptr<type>`
 *
 * The best way to create a shared pointer is to use `make_shared` macro, where we do not
 * have to use `new` and it is like template function. And according to documentation this
 * approach is more efficient than using `new`
 *
 */