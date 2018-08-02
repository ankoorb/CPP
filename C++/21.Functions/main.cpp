#include <iostream>
using namespace std;

void show_menu() {
    cout << "1. Search" << endl;
    cout << "2. View Record" << endl;
    cout << "3. Quit" << endl;
}

void process_selection() {
    cout << "Enter selection: " << endl;

    int input;
    cin >> input;

    switch(input) {
        case 1:
            cout << "Searching ..." << endl;
            break;

        case 2:
            cout << "Viewing ..." << endl;
            break;

        case 3:
            cout << "Quitting ..." << endl;
            break;

        default:
            cout << "Please select an item from the menu!" << endl;
    }

}

int main() {

    // Call defined functions
    show_menu();
    process_selection();

    return 0;
}