#include <iostream>
using namespace std;

int main() {

    string password = "1234";
    cout << "Enter the password > " << flush;

    // Declare a string variable
    string input;
    cin >> input;
    cout << "You entered: '" << input << "'" << endl; // For debugging

    if (input == password) {
        cout << "Access granted." << endl;
    }

    if (input != password) {
        cout << "Access denied." << endl;
    }

    return 0;
}