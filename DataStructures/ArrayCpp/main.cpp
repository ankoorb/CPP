#include <iostream>
#include "Array.h"
using namespace std;

int main() {

    int ch;
    int size;
    int length;
    int x;
    int idx;
    Array* array;
    cout << "Enter Size of Array: " << flush;
    cin >> size;
    cout << "Enter Length of Array: " << flush;
    cin >> length;

    array = new Array(size);

    do {
        cout << endl;
        cout << "Menu" << endl;
        cout << "1.\t Insert" << endl;
        cout << "2.\t Delete" << endl;
        cout << "3.\t Search" << endl;
        cout << "4.\t Sum" << endl;
        cout << "5.\t Display" << endl;
        cout << "6.\t Exit" << endl;

        cout << "\nEnter your choice: " << flush;
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter an element and index: " << flush;
                cin >> x;
                cin >> idx;
                array->Insert(x, idx);
                break;
            case 2:
                cout << "\nEnter index for deleting element: " << flush;
                cin >> idx;
                x = array->Delete(idx);
                cout << "\nDeleted element is: " << x << endl;
                break;
            case 3:
                cout << "\nEnter element to search: " << flush;
                cin >> x;
                idx = array->LinearSearch(x);
                cout << "\nElement index is: " << idx << endl;
                break;
            case 4:
                cout << "\nSum of elements is: " << array->Sum() << endl;
                break;
            case 5:
                array->Display();
        }
    } while (ch < 6);


    return 0;
}