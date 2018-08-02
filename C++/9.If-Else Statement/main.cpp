#include <iostream>
using namespace std;

int main() {

    cout << "1. \tAdd new record." << endl;
    cout << "2. \tDelete record." << endl;
    cout << "3. \tView record." << endl;
    cout << "4. \tSearch record." << endl;
    cout << "5. \tQuit." << endl;

    cout << "Enter your \"selection\": " << flush;

    // Declare an int variable
    int input;
    cin >> input;

    if(input < 3) {
        cout << "Insufficient privileges to use these menu options." << endl;
    }
    else {
        cout << "Privilege level sufficient." << endl;
    }

    if(input == 5) {
        cout << "Quitting." << endl;
    }
    else {
        cout << "Logged in." << endl;
    }


    return 0;
}