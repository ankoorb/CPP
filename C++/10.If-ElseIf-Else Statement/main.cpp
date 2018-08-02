#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout << "1. \tAdd new record." << endl;
    cout << "2. \tDelete record." << endl;
    cout << "3. \tView record." << endl;
    cout << "4. \tSearch record." << endl;
    cout << "5. \tQuit." << endl;

    cout << "Enter your \"selection\": " << flush;
    int input;
    cin >> input;

    if(input == 1) {
        cout << "Adding new record." << endl;
    }
    else if(input == 2) {
        cout << "Deleting record." << endl;
    }
    else if(input == 3) {
        cout << "Viewing record." << endl;
    }
    else if(input == 4) {
        cout << "Searching record." << endl;
    }
    else if(input == 5) {
        cout << "Quitting." << endl;
    }
    else {
        cout << "Invalid option." << endl;
    }

    // Do not use "==" to compare floating point values!
    float x = 3.14;
    cout << fixed << setprecision(4) << x << endl;
    float y;
    cout << "Input a number: " << flush;
    cin >> y;
    if(x == y) {
        cout << "Equal." << endl;
    }
    else {
        cout << "Not equal." << endl;
    }

    return 0;
}