#include <iostream>
using namespace std;

void test() { cout << "Hello" << endl; }

// Function that takes parameters
void print(string s) { cout << "String: " << s << endl; }

int main() {

//    test();

    // variable is pTest which is pointer to a function with a void return type and no parameters
    void (*pTest)();

    //void (*pTest)() = test; // Initialize function pointer when you declare it

    // How to point pointer to function
//    pTest = &test;
    pTest = test;  // This works without address reference too
    // name of the function is in fact pointer to that function

//    (*pTest)();  // Need ( and ) to make sure that dereference operator i.e. * applies to pointer name
    // We do not need dereference operator also
    pTest();

    // Function with parameters
    void (*pPrint)(string) = print;
    pPrint("World");
//
//
//    cout << test << endl;
//    cout << print << endl;

    return 0;
}

/*
 * In C++ 11 one can use Lambda Expression as an alternative to function pointers.
 *
 * In the same way that we can declare a pointer to a variable we can declare a pointer to
 * a function, and we can pass that pointer around so we can actually in effect pass a block
 * of code to another function.
 *
 * Function pointers are actually used even behind the scenes in C++, if you have been using
 * `virtual` methods you have been using them implicitly. Because the `virtual` keyword is an
 * instruction to call C++ to create a v-table (virtual table), which is a table of function
 * pointers so that when you call a method in a child class via a pointer to the parent class
 * type, C++ can do a look up on the table of function pointers and find the right function to
 * call.
 *
 * How to declare a pointer to a function: First thing we need is a variable of right type.
 * Then we can point that variable at a function.
 *
 */

