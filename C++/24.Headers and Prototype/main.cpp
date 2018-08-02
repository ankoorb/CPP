#include <iostream>
#include "utils.h"
using namespace std;

//void do_something(); // Prototype of function defined below main()

int main() {

    cout << "Enter an integer: " << flush;
    int j;
    cin >> j;
    for (int i=0; i<j; i++) {
        do_something();
    }

    return 0;
}

void do_something() {
    cout << "Hello!" << endl;
}