#include <iostream>
using namespace std;

int main() {

    cout << "Enter your name: " << flush; // Keeps cursor in the same line.

    string input; // Declare an empty string variable
    cin >> input;
    cout << "You entered: " << input << endl;

    cout << "Enter an integer: " << flush;
    int value; // Declare an empty integer variable
    cin >> value;
    cout << "You entered: " << value << endl;

    return 0;
}