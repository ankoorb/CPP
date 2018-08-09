#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
    Test(){ cout << "Constructor" << endl; }
    Test(int i){ cout << "Parameterized Constructor" << endl; }
    Test(const Test &other){ cout << "Copy Constructor" << endl; }
    Test &operator=(const Test &other){
        cout << "Overridden assignment" << endl;
        return *this;
    }
    ~Test(){ cout << "Destructor" << endl; }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

//    Test t;
//    cout << t << endl;
//
//    Test s = getTest();
//    cout << s << endl;

    // Problem
    vector<Test> vec;
    vec.push_back(Test());


    return 0;
}

/*
 * In C++ computer programming, copy elision refers to a compiler optimization
 * technique that eliminates unnecessary copying of objects.
 *
 * GCC provides the ‑fno‑elide‑constructors option to disable copy-elision. However,
 * it is not a good idea to disable copy-elision.
 *
 * C++ can do Return Value Optimization which involves eliding or getting rid of extra
 * copes of objects. Extra copies happen in a situation where you are running some
 * sort of local variable from a function and you are using it to initialize another
 * object outside of the function, e.g. `Test s = getTest();`
 *
 */