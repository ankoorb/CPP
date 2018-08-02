#include <iostream>
using namespace std;

int main() {

    /*
    // Endless loop
    while(true) {
        cout << "Hello!" << endl;
    }*/

    int i = 0;
    while (i <= 5) {
        cout << "Hello! i: " << i << endl;
        i++; // Increments i by 1
    }
    cout << "Program Quitting!" << endl;

    return 0;
}