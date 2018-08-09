#include <iostream>
using namespace std;

void test(void (*p_func)()){
    p_func();
}

int main() {

    // Lambda expression and calling it
    [](){ cout << "Hello!" << endl; }();


    // Storing reference to lambda function
    auto func = [](){ cout << "Hello!" << endl; };
    func();

    // Passing lambda expression to a function
    test(func);

    cout << func << endl;


    return 0;
}

/*
 * Lambda Expressions - A function which does not have a name that can be passed around.
 *
 * [] are distinctive feature of lambda expressions that enables them to be recognized,
 * `[](){};` is a valid lambda expression. The code is usually written inside {}. The
 * function can be stored in a variable using `auto`, i.e. the reference to anonymous
 * function is stored in a variable using `auto`.
 *
 * C++ usually often infer the return type of a lambda expression.
 *
 */