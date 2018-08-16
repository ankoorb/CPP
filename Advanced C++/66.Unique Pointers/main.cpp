#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
    Test(){ cout << "created" << endl; }
    void greet(){ cout << "Hello!" << endl; }
    ~Test(){ cout << "destroyed" << endl; }
};

class Temp {
private:
    unique_ptr<Test []> pt;
public:
    Temp():pt(new Test[2]){}
};

int main() {

//    unique_ptr<int> ptest(new int);
//    cout << *ptest << endl;
//    *ptest = 7;
//    cout << *ptest << endl;

    {
        // C++ 11 use unique_ptr instead of auto_ptr
        unique_ptr<Test> ptest(new Test);
        ptest->greet();
    }

    {
        // C++ 98 -> auto_ptr are depreciated so do not use
        auto_ptr<Test> ptest(new Test);
        ptest->greet();
    }

    {
        // Array
        unique_ptr<Test []> ptest(new Test [2]);
        ptest[0].greet();
    }

    {
        Temp temp;
    }


        cout << "Finished" << endl;


    return 0;
}

/*
 * Unique pointers - These are kind of smart pointer which behaves like a normal pointer
 * except they handle the de-allocation of memory for you.
 *
 * Memory leaks are a common problem in C++ programs because you do not get enough
 * deletes being called or the right type of delete for the objects you have allocated
 * using `new`. Smart pointers are help you avoid those bugs by automatically de-allocating
 * memory.
 *
 * `unique_ptr<type pointer is going to point at> variable` - It is a template type. We want
 * this to manage the memory that will be allocated by `new` we can not use `new type`
 * e.g. unique_ptr<int> px = new int;, we need to allocate memory within ().
 *
 * NOTE: To use unique pointers you need to use `#include <memory>` and `using namespace std;`
 * #include <iostream> is already including memory so do not need `#include <memory>`, if
 * not use `#include <memory>`
 *
 * Unique pointer or smart pointers in general clean up memory when the variable they are
 * associated with goes out of scope.
 *
 * `auto_ptr` can not be used on arrays however `unique_ptr` can be used on arrays.
 *
 */