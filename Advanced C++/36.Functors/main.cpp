#include <iostream>
using namespace std;

// Base struct
struct Test {
    virtual bool operator()(string &text)=0;
    virtual ~Test(){}
};

struct MatchTest: public Test {
    bool operator()(string &text) {
        return text == "lion";
    }
};

//// This is a functor
//struct MatchTest {
//    bool operator()(string &text){ // First () is for overriding ()
//        return text == "lion";
//    }
//};

// Passing functor to a function
void check(string text, Test &test){
// Need to pass a reference for polymorphism to operate correctly
// i.e. must be a reference if we want to pass in different tests

        if(test(text)){
            cout << "Text matches!" << endl;
        } else {
            cout << "No match!" << endl;
        }
}


int main() {

    MatchTest tester;

    string value = "lions";

    cout << tester(value) << endl;
    // Looks like a function call, but it is not. It is round brackets operator being
    // applied using MatchTest object to value

    check(value, tester);



    return 0;
}

/*
 * Functors are another way of passing blocks of codes to functions. They are kind of alternative
 * to function pointers. There are some things you can do with functors that you can not do with
 * function pointers. This is kind of alternative thing you can use in C++ 11.
 *
 * Overloading () operator -> Round brackets, i.e. (), are operator and they are different to
 * every other operator in C++. They can take a variable list of arguments, they can take no
 * arguments or as many arguments as needed. So () operator is the only operator that can take
 * a variable list of arguments.
 *
 * Functor is a class or a struct that among other things it overloads () operator.
 *
 * Passing functor to other functions e.g. check, the idea is that check can apply different
 * kinds of testers, i.e. we want to be able to pass different kinds of tests to it so we can
 * achieve this by having a base class of Functor
 *
 * NOTE: We can not pass literal values e.g. tester("lion") if function argument is reference
 */