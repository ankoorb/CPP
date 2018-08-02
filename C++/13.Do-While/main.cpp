#include <iostream>
using namespace std;

int main() {

    int value = 7;

    do {
        cout << "Hello!" << endl;
    } while (value < 5);

    // const - Makes variable not re-assignable
    const string password = "hello";

    string input;

    // Do While - Avoid repeated code
    do {
        cout << "Enter your password: " << flush;
        cin >> input;

        if (input != password) {
            cout << "Access denied." << endl;
        }
    } while (input != password);

    cout << "Access approved." << endl;

    return 0;
}