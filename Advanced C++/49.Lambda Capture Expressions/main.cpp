#include <iostream>
using namespace std;

int main() {

    int u = 0;
    int v = 1;
    int w = 2;

    // [](){ cout << v << endl; }(); // error: variable 'v' cannot be implicitly captured in a lambda with no capture-default specified

    // Capture by value
    [v](){ cout << v << endl; }();
    [v, w](){ cout << v + w << endl; }();

    // Capture all local variables by value
    [=](){ cout << v + w << endl; }();

    // Capture some local variables by value and other by reference
    [=, &u](){ u = 7; cout << v + u * w << endl; }();

    // Capture all local variables by reference
    [&](){ v = 2; w = 15; cout << w << endl; }();

    // Capture all local variables by reference but a couple of variables by value
    [&, w](){ v = 2; u = 7; cout << "u: " << u << endl; }();

    return 0;
}

/*
 * Capture expressions in lambda expressions - Capture brackets
 *
 * `[](){ cout << v << endl; }();` - Value of local variable v can not be immediately
 * used because the lambda expression has its own scope. So running this results in
 * error. So need to use [] to capture local variables. Use `[=]` to capture all the
 * local variables by value. Use `[&]` to capture all the local variables by reference
 *
 * Capturing some variables by value and others by reference - The = sign has to be
 * the first symbol in the capture expression, then specify all the variables that
 * need to be captured by reference.
 *
 */