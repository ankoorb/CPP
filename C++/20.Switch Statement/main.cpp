#include <iostream>
using namespace std;

int main() {

    int value;
    cout << "Enter an integer: " << endl;
    cin >> value;

    switch(value) {
        case 4:
            cout << "Value is 4." << endl;
            break;

        case 5:
            cout << "Value is 5." << endl;
            break;

        case 6:
            cout << "Value is 6." << endl;
            break;

        default:
            cout << "Unrecognized value." << endl;
            break;

    }

    return 0;
}