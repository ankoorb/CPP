#include <iostream>
using namespace std;

int main() {

    // Break
    for(int i=0; i<5; i++) {
        cout << "i is: " << i << endl;

        if(i == 2) {
            break;
        }
        cout << "Looping..." << endl;
    }
    cout << "Program quitting." << endl;

    // Continue
    for(int i=0; i<5; i++) {
        cout << "i is: " << i << endl;

        if(i == 2 || i == 3) {
            continue;
        }
        cout << "Looping..." << endl;
    }
    cout << "Program quitting." << endl;

    // Do While with break
    const string password = "hello";
    string input;

    do {
        cout << "Enter your password: " << flush;
        cin >> input;

        if(input == password) {
            break;
        } else {
            cout << "Access denied." << endl;
        }
    } while(input != password);

    cout << "Access approved" << endl;
    cout << "Program quitting." << endl;

    return 0;
}