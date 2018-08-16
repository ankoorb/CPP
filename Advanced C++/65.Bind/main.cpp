#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
    cout << "a, b, c: " << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int run(function<int(int, int)> func){
    return func(7, 3);
}

// Binding to Method
class Test {
public:
    int add(int a, int b, int c){
        cout << "a, b, c: " << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

int main() {

//    cout << add(1, 2, 3) << endl;
//
//    auto sum = bind(add, 1, 2, 3);
//    cout << sum() << endl;

    auto sum = bind(add, _1, _2, _3);
    cout << sum(3, 4, 5) << endl;

    auto mix = bind(add, _1, 100, _2);
    cout << mix(1, 2) << endl;

    cout << run(mix) << endl;

    // Binding to method
    Test xyz;
    auto method = bind(&Test::add, xyz, 2, 100, 1);  // Pointer to add method or reference
    cout << method() << endl;  // And second argument is object of class to bind to

    return 0;
}


/*
 * Boost C++ Library (collection of C++ libraries)
 *
 * `bind` - It allows to create kind of aliases to functions, a bit like function
 * pointers. Need to use `functional` header.
 *
 * Use `bind(function_pointer, function_arguments)` and bound to some `auto` variable.
 * Now the bound variable can be called, and everytime bound variable is called it will
 * be supplied with the arguments that were used during binding.
 *
 *
 * namespace `placeholders` and using `functional` -> can pass arguments like `_1`,
 * `_2`, `_3` and so on.
 *
 * Placeholders and actual arguments can be combined - Placeholders are always numbered
 * and the their order can be changed, e.g. `bind(add, _2, _1, _3)` is example of
 * order change.
 *
 * Mix and match - bind(add, _1, 100, _2);
 *
 *
 *
 */