#include <iostream>
using namespace std;

int main() {

    int dogs = 7;
    [dogs]() mutable {
        dogs = 15;
        cout << "lambda expression scope: " << dogs << endl;
    }();

    cout << "outside lambda expression: " << dogs << endl;

    return 0;
}

/*
 * error: cannot assign to a variable captured by copy in a non-mutable lambda
 *
 * If a variable is captured by value the lambda expression does not allow to assign
 * value to that variable.
 *
 * mutable - Make a variable mutable withing the scope of lambda expression
 */